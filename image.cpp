#include "image.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

  Image::Image(int numRows, int numCols, int grayLevels)
/* Creates an Image of numRows x numCols and creates the arrays for it*/
{	
	
	N = numRows;
	M = numCols;
	Q = grayLevels;
	
} 

Image::~Image(){}

int Image::readImage(char fname[])
{
	int i, j;
	int N, M, Q;
	unsigned char *charImage;
	char header [100], *ptr;

	ifstream ifp;
	ifp.open(fname, ios::in | ios::binary);

	if (!ifp) 	//error checking
	{
		cout << "Can't read image: " << fname << endl;
		return(-1);
	}

 // read header

	ifp.getline(header,100,'\n');		//magic number
	if ( (header[0]!=80) || (header[1]!=50) )	  //if not P5
	{   
		cout << "Image " << fname << " is not PGM" << endl;
		return(-1);
	}

	ifp.getline(header,100,'\n');
	while(header[0]=='#')		//file name line in file starts with #
		ifp.getline(header,100,'\n');

	M=strtol(header,&ptr,0);	//number of colums
	N=atoi(ptr);			//number of rows

	ifp.getline(header,100,'\n');
	Q=255;	//max gray value

	charImage = (unsigned char*) new unsigned char [M*N];	//creates 2D array

	ifp.read( reinterpret_cast<char *>(charImage), (M*N)*sizeof(unsigned char));  //reads in 2D array

	if (ifp.fail()) 
	{
		cout << "Image " << fname << " has wrong size" << endl;
		return(-1);
	}

	ifp.close();

 // Convert the unsigned characters to integers

	int val;

	for(i=0; i<N*M; i++){
			val = (int)charImage[i];
			pixelVal.push_back(val);	 
		}

	delete [] charImage;

	return (1);
}

int readImageHeader(char fname[], int& N, int& M, int& Q, bool& type)
{
	int i, j;
	unsigned char *charImage;
	char header [100], *ptr;
	
	ifstream ifp;
	ifp.open(fname, ios::in | ios::binary);

	if (!ifp) 
	{
		cout << "Can't read image: " << fname << endl;
		return(-1);
	}

 // read header

//*************************
//this section will not be used in this tutorial, this is used for programs that can handle color images

	type = false;   // PGM

	ifp.getline(header,100,'\n');
	if ( (header[0] == 80) && (header[1]== 50) ) 
	{  
	  type = false;
	}
	else if ( (header[0] == 80) && (header[1] == 54) ) 
	{	   
	  type = true;
	} 
	else 
	{
		cout << "Image " << fname << " is not PGM or PPM" << endl;
		return(-1);
	}

//*****************************

	ifp.getline(header,100,'\n');
	while(header[0]=='#')
		ifp.getline(header,100,'\n');

	M=strtol(header,&ptr,0);
	N=atoi(ptr);

	ifp.getline(header,100,'\n');

	Q=255;

	ifp.close();

	return(1);
}
