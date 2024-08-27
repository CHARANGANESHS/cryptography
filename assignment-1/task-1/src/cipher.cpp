#include "../include/cipher.hpp"
#include "../include/readfile.hpp"

using namespace std;

Cipher::Cipher(int key, string filename){
    this->key = key;
    this->filename = filename;
    for(int i = 0; i < 26; i++){
        this->mp1['a' + i] = i;
        this->mp2[i] = 'a' + i;
    }
}

string Cipher::encrypt(){
    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return "-1";
    }

    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'a' && a <= 'z'){
            int index = this->mp1[a];
            index = (index + this->key) %26;
            file_content[i] = this->mp2[index];
        }
    }

    return file_content;
}

string Cipher::decrypt(){
    
    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return "-1";
    }

    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'a' && a <= 'z'){
            int index = this->mp1[a];
            index = (index - this->key + 26) %26;
            file_content[i] = this->mp2[index];
        }
    }
    
    return file_content;
}