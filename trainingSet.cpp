#include <string.h>
#include <vector>
#include "trainingSet.h"

using namespace std;

trainingSet::trainingSet(const char* pictureList) { //List of pictures to use for training

    int i = 0;

    std::ifstream list;
    list.open(pictureList);

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
    
    while(!pictures.empty()){
        std::vector<char> v (readPic(pictures.back()));
        testdata.push_back(v);
        pictures.pop_back();
    }
    
}
trainingSet::~trainingSet() {

}

std::vector<char> trainingSet::readPic(char* pictureLocation){  //reading a picture

	std::vector<char> pictureVector;
	char buffer[1];

	std::ifstream fPic;

    cout << "Reading: " << pictureLocation << endl; 

	fPic.open(pictureLocation);

	if(fPic.is_open()){
		for(int i = 0; i<600; i++){       //reading every 32nd bit
			fPic.read(buffer, 1);
			fPic.seekg(32, fPic.cur);
			pictureVector.push_back(buffer[0]);
		}
		
	}
	fPic.close();

	return pictureVector;

}

