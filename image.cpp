//  Image.cpp
//

#ifndef _Image_h
#define _Image_h
#define SIZE 16384

#include "Image.h"
#include <string.h>
#include <cmath>

#endif

using namespace std;


//Constructor

MImage::MImage(const char* fileName){

    imageData = new char[SIZE];
    //image I/O
    pInFile = new ifstream;
    pInFile->open(fileName, ios::in | ios::binary); // open fileName and read as binary.
    pInFile->seekg(0, ios::beg); //pos filter at beginning of image file.
    pInFile->read(imageHeaderData,1078); //read bmp header data into array.
    pInFile->read(imageData,SIZE);//read image data.
    

    pInFile->close(); //close stream.

}

MImage::~MImage(){

    delete pInFile;
    delete pOutFile;
}

char* MImage::value(){
    return imageData;
}
void MImage::print(){
    for(int i=1; i < SIZE-1; i++){
        cout << imageData[i];
    }
}