#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <pthread.h>
#include <stdio.h>
#include <vector>

/*
    Use concurrency (using multi-threading) to calculate 
    the scores for atheletes based on factors such lifts, 
    weight, and age. 
    
    Also, use mutexes to solve the critical section problem. 
    For more on critical section:
    https://www.javatpoint.com/os-critical-section-problem
*/

static pthread_mutex_t mutex;
static double score;
static nlohmann::json jObject;


// parse json file
static nlohmann::json get_parsed_json(const std::string fileName){
    std::ifstream stream(fileName);
    return nlohmann::json::parse(stream);
}


// if they are not young or old, then they have advantage
static bool has_advantage(const int age){
    if(age >= 25 && age <= 40){
        return true;
    }
    return false;
}


// calculate the score
static void* calculate_score(void* arg){
    // struct data_struct *data = (struct data_struct*) arg;    
    double deadlift = jObject["deadlift"];
    double squats = jObject["squats"];
    double bench = jObject["bench"];
    double weight = jObject["weight"];
    double age = jObject["age"];

    pthread_mutex_lock(&mutex);
    double combinedLift = deadlift + squats + bench;  
    pthread_mutex_unlock(&mutex); 

    pthread_mutex_lock(&mutex);
    score = combinedLift / weight;
    pthread_mutex_unlock(&mutex); 

    // give bonus to the athlete if they are very young or old
    pthread_mutex_lock(&mutex);
    if(!has_advantage(age)){
        score += 1.0;
    }
    pthread_mutex_unlock(&mutex); 

    pthread_exit(0);
}


// calculate the score for the athlete based on their lift
static std::vector<nlohmann::json> get_scores(nlohmann::json jsonArr){
    const int NUM_THREADS = jsonArr.size();
    pthread_t thread_ids[NUM_THREADS];
    
    std::vector<nlohmann::json> jObjects;

    int count = 0;
    for(nlohmann::json j : jsonArr){
        if(count > NUM_THREADS){
            break;
        }

        jObject = j;
		pthread_create(&thread_ids[count], NULL, calculate_score, NULL);
        pthread_join(thread_ids[count], NULL);
        count++;

        j["score"] = score;
        jObjects.push_back(j);
    }

    return jObjects;
}


// write the new json file with newly calculated scores
static void write_json_file(const std::string readFile, const std::string writeFile){
    nlohmann::json jsonArr = get_parsed_json(readFile);
    std::vector<nlohmann::json> newData = get_scores(jsonArr);

    // write new json file
    std::ofstream writer(writeFile);
    writer << std::setw(4) << newData << std::endl;
}


void execute(){
    const std::string readFile = "raw_data.json";
    const std::string writeFile = "data_with_scores.json";
    write_json_file(readFile, writeFile);
}
