#ifndef WRITEFILE_HPP
#define WRITEFILE_HPP

#include <iostream>
using namespace std;

class WriteFile{
public:
    WriteFile(string filename);
    void write(string text);

private:
    string filename;
};

#endif // WRITEFILE_HPP