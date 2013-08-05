#include "image.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

  Image::Image()
{	
	
} 

Image::~Image(){}

int Image::readImage(char fname[], int count)
{
	int j;
	char header[100];
	pixelVal = new double[784];

	ifstream ifp;

	ifp.open(fname, ios::in | ios::binary);
	ofstream ofp("debug.txt");

	if (!ifp) 	//error checking
	{
		cout << "Can't read image: " << fname << endl;
		return(-1);
	}
	ifp.seekg(count, ifp.beg); //moves to current position in the data file

 // read header

	//ifp.getline(header,100,'\n');		//magic number

//	ifp.getline(header,100,'\n');
//	while(header[0]=='#')		//file name line in file starts with #
//		ifp.getline(header,100,'\n');

//	ifp.getline(header,100,'\n');

	int val;
	unsigned char i[1];
	for(j = 0; j < 784; j++){  //reads in values and converts them to integers
		ifp.read((char*)i, 1);
		
		val = i[0];
		//ofp << "Read in Value: " << val << "|";
		if(val != 0){
			val = 1;
		}
		
		ofp <<val;
		pixelVal[j] = val;
		
	}  

	ifp.close();

	return (1);
}

