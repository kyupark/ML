#include <fstream> // for file I/O
#include <vector>

using namespace std;

class trainingSet {

public:
	
    trainingSet(const char* pictureList); //Constructor
    ~trainingSet(); //Deconstructor
    std::vector<char> readPic(char* pictureLocation); //return row of image data
    std::vector< vector<char> > testdata;			  //use this to access the data
private:
	std::vector<char*> pictures;
	

};
