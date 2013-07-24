#ifndef NNetwork
#define NNetwork

#include "trainingDataSet.h"
#include "dataEntry.h"

class neuralNetworkTrainer;

class neuralNetwork
{
	//class members
	//--------------------------------------------------------------------------------------------
private:

	//number of neurons
	int nInput, nHidden, nOutput;
	
	//neurons
	std::vector<double> inputNeurons;
	std::vector<double> hiddenNeurons;
	std::vector<double> outputNeurons;

	//weights
	std::vector<std::vector<double> > wInputHidden;
	std::vector<std::vector<double> > wHiddenOutput;
		
	//Friends
	//--------------------------------------------------------------------------------------------
	friend class neuralNetworkTrainer;
	
	//public methods
	//--------------------------------------------------------------------------------------------

public:

	//constructor & destructor
	neuralNetwork(int numInput, int numHidden, int numOutput);
	~neuralNetwork();

	//weight operations
	bool loadWeights(char* inputFilename);
	bool saveWeights(char* outputFilename);
	int* feedForwardPattern( std::vector<double> pattern );
	double getSetAccuracy( std::vector<dataEntry >& set );
	double getSetMSE( std::vector<dataEntry >& set );

	//private methods
	//--------------------------------------------------------------------------------------------

private: 

	void initializeWeights();
	inline double activationFunction( double x );
	inline int clampOutput( double x );
	void feedForward( std::vector<double> pattern );
	
};

#endif
