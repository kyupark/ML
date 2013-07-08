//  Image.h

#include <fstream> // for file I/O

using namespace std;

class MImage {

public:
    MImage(const char* fileName); //Constructor
    ~MImage(); //Deconstructor
    char* value(); //return row of image data
    void print(); //prints row of data
private:
    ifstream* pInFile; 
    ofstream* pOutFile;
    char imageHeaderData[1078]; //.bmp header data with offset 1078.
    char* imageData;
};