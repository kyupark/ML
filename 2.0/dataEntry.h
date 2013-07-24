#ifndef _DATAENTRY
#define _DATAENTRY

//standard libraries
#include <iostream>
#include <vector>

using namespace std;

class dataEntry
{
public:
	
	//public members
	//----------------------------------------------------------------------------------------------------------------
	std::vector<double> pattern;	//all the patterns
	std::vector<double> target;		//all the targets

public:

	//public methods
	//----------------------------------------------------------------------------------------------------------------

	//constructor
	dataEntry(std::vector<double> p, std::vector<double> t): pattern(p), target(t) {}
		
	~dataEntry()
	{				
		
	}

};

#endif
