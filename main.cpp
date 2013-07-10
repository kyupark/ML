#include <iostream>
#include "trainingSet.cpp"
#include <fstream>
#include <string.h>

using namespace std;

int main() {

	int a;
	trainingSet test("testpics.txt");
	printf("hello\n");
	vector<char> x (test.testdata[0]); //just testing to see if anything got written in

	cout << x[599];

	cin >> a; // stops the program so I can look at the output

    return 0;

}