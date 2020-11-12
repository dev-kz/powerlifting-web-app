# powerlifting-web-app
Used many languages to communicate with each other in order to run a web app.

> *What is the overall goal of the project (i.e. what does it do, or what problem is it solving)?*

I wanted to create a web application to study the data from a powerlifting comptetition, and 
be able to find ways of analyzing the data to better understand the atheletes and the competition.


> *Which languages did you use, and what parts of the system are implemented in each?*

C/C++, Python, Javascript


> *What methods did you use to communicate between languages?*

Python uses SWIG to make a function call to C/C++. C/C++ generates a data file. Javascript then takes
the newly generated data file, work with it, and create a new one. Python then takes a newly taken 
data file for analysis and web app visualizations.


> *Exactly what steps should be taken to get the project working, after getting your code? [This should start with vagrant up and can include one or two commands to start components after that.]*

**Note:** Please follow step 5 and after if you don't see anything on localhost:5000 or localhost:9000 in the browser while you are ssh in vagrant.

1. $ vagrant up
2. $ vagrant ssh
3. $ chmod +x run.sh
4. $ ./run.sh
5. $ ctrl + c   
6. $ exit
7. python3 app.py 
 

> *What features should we be looking for when marking your project?*

1. I implemented concurrency (multithreading) using pthread library from C/C++. I then
used mutexes to solve the critical section problem during my calculations.
2. I used Python flask for the REST-APIs and data analysis/visualization using Pandas library.
3. I used node.js to sort the output of C/C++ files.
4. I used SWIG (for function call) and read/write files for language communications.
5. I used HTML/CSS for the frontend.

