#include "../include/plain.hpp"
#include "../include/readfile.hpp"

using namespace std;

Plain::Plain(string filename, string key) : filename(filename), key(key) {
    this->filename = filename;
    this->key = key;
    for (int i = 0; i < 26; ++i) {
        this->mp1['a' + i] = key[i];
        this->mp2[key[i]] = 'a' + i;
    }
}

string Plain::encrypt() {
    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1") {
        cout << "File not found" << endl;
        return "-1";
    }

    string cipheredtext;
    for (int i = 0; i < file_content.size(); ++i) {
        if (this->mp1.find(file_content[i]) != this->mp1.end()) {
            cipheredtext += this->mp1[file_content[i]];
        } 
        else {
            cipheredtext += file_content[i]; 
        }
    }

    return cipheredtext;
}

string Plain::decrypt() {

    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1") {
        cout << "File not found" << endl;
        return "-1";
    }

    string decryptedtext;
    for (int i = 0; i < file_content.size(); ++i) {
        if (this->mp2.find(file_content[i]) != this->mp2.end()) {
            decryptedtext += this->mp2[file_content[i]];
        } 
        else {
            decryptedtext += file_content[i];
        }
    }

    return decryptedtext;
}