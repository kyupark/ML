
//standard libraries
#include <iostream>
#include <fstream>

//custom includes
#include "neuralNetwork.h"
#include "image.h"

//use standard namespace
using namespace std;

int main(){
	int i;
	unsigned char buffer[784];
	double data[784];
	int temp;


	neuralNetwork nn(784,25,10);
	nn.loadWeights("weights.csv"); //loads wieghts from previous neural network run
	ifstream pic("inputPic.txt"); //loads picture created in python
	ofstream output("output.txt"); // writes the NN's guess to output file
	ofstream d("debug.txt");
	
	    

    //read in the drawn picture data
    if(pic.is_open()){
        pic.getline((char*)buffer, 784);
        pic.close();
    }
    else 
	{
		cout << "Error Opening Input File..." << endl;
		char c; cin >> c;
		return 0;
	}
    //=============================Test begins========================================

    for(i = 0; i<784; i++){
    	temp = buffer[i];		//get data from buffer
    	if(temp == 0){
    		data[i] = 0;
    	}else{
    		data[i] = temp - 48;
    		d << data[i] << endl;
    	}

    }

    double* result = nn.feedForwardPattern(data);
    double max = 0;
    int ans = -1;
    for(i = 0; i<10; i++){
    	if(result[i] > max){
    		max = result[i];
    		ans = i;
    	}
    	cout << result[i] << endl;
    }

	if(output.is_open()){
		output << ans;
	}else{
		cout << "Failed to write to output file..." << endl;
		return 0;

	}
	return 0;
}
