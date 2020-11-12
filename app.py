from flask import Flask, render_template
from writer import execute		### C++ function
import json
from analysis import get_data_as_df, get_highest_score, get_lowest_score
import os

app = Flask(__name__)


def read_data():
	with open('sorted_final_data.json') as f:
		info = json.load(f)
	return info

@app.route("/") 	
def report():
	return render_template("home.html", info = read_data())

@app.route("/analysis")
def analysis():
	df = get_data_as_df()
	winner = [json.loads(get_highest_score(df))]
	lowest = [json.loads(get_lowest_score(df))]

	return render_template("analysis.html", title = "Analysis", 
											won = winner, 
											lost = lowest)    

if __name__ == "__main__":
	app.run(debug=True, use_reloader=False)