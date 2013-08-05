#ifndef IMAGE_H
#define IMAGE_H
#include <fstream>
#include <vector>
using namespace std;

class Image
{
	  public:
			 Image(); 							//constructor
			 ~Image();						//destructor
			 int readImage(char fname[], int count);
			 double* pixelVal;						//pixel array
	  private:
};

#endif


