#pragma pack(1)

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "bmp.h"

vector<char> buffer;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

void fill() {
    std::ifstream file("test.bmp");

    if (file) {
        file.seekg(0,std::ios::end);
        streampos length = file.tellg();
        file.seekg(0,std::ios::beg);

        buffer.resize(length);
        file.read(&buffer[0],length);

        file_header = (PBITMAPFILEHEADER)(&buffer[0]);
        info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));
    }
}

int main() {
    fill();

    cout << buffer[0] << buffer[1] << endl;
    cout << file_header->bfSize << endl;
    cout << info_header->biWidth << " " << info_header->biHeight << endl;

    return 0;
}
