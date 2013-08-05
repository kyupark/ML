
//standard libraries
#include <iostream>
#include <ctime>
#include <stdlib.h>

//custom includes
#include "neuralNetwork.h"
#include "neuralNetworkTrainer.h"
#include "image.h"

//use standard namespace
using namespace std;

int main()
{	
	//seed random number generator
	srand( (unsigned int) time(0) );
	
	//create data set reader and load data file
	dataReader d;
	d.loadDataFile("datasets.txt");
	d.setCreationApproach( STATIC, 10 );	

	//create neural network
	neuralNetwork nn(784,25,10);

	cout << "Desired Learning rate: ";
	double LR; cin >> LR;
	cout << endl << "Desired Momentum: ";
	double MM; cin >> MM;
	cout << endl << "Starting Training..." << endl;

	//create neural network trainer
	neuralNetworkTrainer nT( &nn );
	nT.setTrainingParameters(LR, MM, false);
	nT.setStoppingConditions(1000, 90);
	nT.enableLogging("log.csv", 5);
	
	//train neural network on data sets
	for (int i=0; i < d.getNumTrainingSets(); i++ )
	{
		nT.trainNetwork( d.getTrainingDataSet() );
	}	

	//save the weights
	nn.saveWeights("weights.csv");
		
	cout << endl << endl << "-- END OF PROGRAM --" << endl;
	char c; cin >> c;

	return 0;

}
