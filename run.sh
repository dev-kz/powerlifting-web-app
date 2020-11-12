#### Remove unncessary files
npm install;
pip3 install -r requirements.txt
sudo apt install swig;

rm -rf *.o *.cxx *.so data_with_scores.json sorted_final_data.json;
rm static/images/*.png;

# #### Link Python and C++ using SWIG
 swig -c++ -python -py3 writer.i;
 g++ -c -fpic writer.cpp writer_wrap.cxx -I/usr/include/python3.6;
 g++ -shared writer.o writer_wrap.o -o _writer.so -lstdc++;

# #### call c++ function using Python and SWIG
 python3 caller.py;

# #### check if the file is ready to be sorted
 node js/app.js;

# #### generate some visualizations and save them
 python3 analysis.py;

# #### run the Flask web application
 python3 app.py;
