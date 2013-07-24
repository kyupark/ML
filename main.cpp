//Imports
#include <string.h>
#include <vector>
#include <fstream>

//Classes
#include "dataEntry.h"
#include "image.cpp"
#include "neuralNetworkTrainer.cpp"
#include "neuralNetwork.cpp"

using namespace std;

int main()
{
    //=======================================Setup=====================================
	int M, N, Q; // rows, cols, grayscale
	int val;
	bool type;

    //current data set
    trainingDataSet tSet;

	std::vector< dataEntry > testdata;
	std::vector<char*> pictures;

    std::ifstream list;
    list.open("testpics.txt");

    //read in filenames for pictures
    if(list.is_open()){
        list.seekg(0, list.end);
        int x = list.tellg();   //get the length
        list.seekg(0, list.beg);

        char* buffer;
        while(!list.eof()){
            buffer = new char[50];
            list.getline(buffer, 50);   //reads the file name(the length has to be under 50 characters)
            pictures.push_back(buffer);
        }
        list.close();
    }
    
    //=============================Data read in begins========================================
    while(!pictures.empty()){
		
		// read image header
		readImageHeader(pictures.back(), N, M, Q, type);

		// allocate memory for the image array
		Image image(N, M, Q);

		// read image
		image.readImage(pictures.back());
		std::vector<double> v (image.pixelVal);

        //get the number from picture name
        std::vector<double> ans;
        int picVal = (int)pictures.back()[0];

        for(int j = 0; j < 10; j++){  //formating the validation data. For example: 3 would be (0,0,0,1,0,0,0,0,0,0)
            if(j == picVal){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        
        dataEntry de = dataEntry(v, ans);
        testdata.push_back(de);

        //remove picture from list
		pictures.pop_back();
    }

    for(int i = 0; i < testdata.size(); i++){
        if(i <= 1){
            tSet.generalizationSet.push_back(testdata[i]);       //partitioning the data
        }else if(i >=8){
            tSet.validationSet.push_back(testdata[i]);
        }else{
            tSet.trainingSet.push_back(testdata[i]);
        }
    }
    //=======================================Training Begins================================
    //create neural network
    neuralNetwork nn(16384,16,10);

    //create neural network trainer
    neuralNetworkTrainer nT( &nn );
    nT.setTrainingParameters(0.001, 0.9, false);
    nT.setStoppingConditions(150, 90);
    nT.enableLogging("log.csv", 5);
    
    //train neural network on data set
    nT.trainNetwork(&tSet);  

    //save the weights
    nn.saveWeights("weights.csv");
        
    cout << endl << endl << "-- END OF PROGRAM --" << endl;
    char c; cin >> c;

    return 0;
}

