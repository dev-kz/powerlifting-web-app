'use strict';
const fs = require('fs');

// read and parse raw data
let rawdata = fs.readFileSync('data_with_scores.json');
let data = JSON.parse(rawdata);

// sort data basde on score (high to low)
data.sort(function (a, b) {
  return a.score < b.score;
});

// make json pretty
let temp = JSON.stringify(data, null, 4);

// write sorted file
fs.writeFileSync('sorted_final_data.json', temp);




// const express = require('express');
// const app = new express();


// const port = 5000

// // var bodyParser = require('body-parser');
// // app.use(bodyParser.json());

// app.use(express.static(__dirname + "/views"));

// // app.post(['/analysis', '/analysis.html'], function(req, res) {});
// // app.post(['/', '/index.html'], function(req, res) {});
// // app.post('/', function(request, response) { 
// //   res.render("index", { title: "Home"});
// // });     


// app.get('/', function(request, response){
//   response.sendFile('home.html');
// });

// app.get('/analysis', function(request, response){
//   response.sendFile('analysis.html');
// });


// // app.post('/analysis', function(request, response) { 
// //   res.render("analysis", { title: "Analysis"});
// // });     
// // // app.post('/analysis', function(request, response) { 
// //   response.redirect('/analysis')
// // });            


// app.listen(port, () => console.log(`Running at port ${port}`));


// // 'use strict';

// // const fs = require('fs');

// // fs.readFile('../data_with_scores.json', (err, data) => {
// //     if (err) throw err;
// //     let student = JSON.parse(data);
// //     console.log(student);
// // });

// // console.log('This is after the read call');


