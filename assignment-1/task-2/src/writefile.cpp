#include "../include/writefile.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

WriteFile::WriteFile(string filename){
    this->filename = filename;
}

void WriteFile::write(string text){
    ofstream file;
    file.open(this->filename);

    if (!file.is_open()){
        cout << "File not found" << endl;
        return;
    }

    file << text;
    file.close();
}