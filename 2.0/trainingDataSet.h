class trainingDataSet
{
public:

	std::vector<dataEntry* > trainingSet;
	std::vector<dataEntry* > generalizationSet;
	std::vector<dataEntry* > validationSet;

	trainingDataSet(){}
	
	void clear()
	{
		trainingSet.clear();
		generalizationSet.clear();
		validationSet.clear();
	}
};