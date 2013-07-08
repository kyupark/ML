//
//  Main.cpp
//

#include <iostream>
#include "image.cpp"
#include <fstream>
#include <string.h>

using namespace std;

int main() {

    MImage img("test.bmp");
    //std::string str(img.value());
    std::string exits;

    img.print();
    cout << "Enter Something: ";
    cin >> exits;

    return 0;

}