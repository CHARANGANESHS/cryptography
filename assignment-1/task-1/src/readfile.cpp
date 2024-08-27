#include "../include/readfile.hpp"

using namespace std;

ReadFile::ReadFile(string filename){
    this->filename = filename;
}

string ReadFile::read(){
    ifstream file(this->filename);
    if(!file.is_open()){
        cout << "File not found" << endl;
        return "-1";
    }

    stringstream buffer;
    buffer << file.rdbuf();

    string file_content = buffer.str();
    file.close();
    
    return file_content;
}