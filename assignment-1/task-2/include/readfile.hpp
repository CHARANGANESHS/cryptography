#ifndef READFILE_HPP
#define READFILE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ReadFile{
public:
    ReadFile(string filename);
    string read();

private:
    string filename;
};

#endif // READFILE_HPP