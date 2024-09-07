#include "../include/cipher.hpp"
#include "../include/readfile.hpp"
#include <bits/stdc++.h>
using namespace std;

Cipher::Cipher(string filename, map<char, double> mp1){
    this->filename = filename;
    this->mp1 = mp1;
    this->size = 0;
}

int Cipher::cipherattack(){

    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return -1;
    }


    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'A' && a <= 'Z'){
            this->mp3[a]++;
            this->size++;
        }
        else{
            cout << "Invalid character found" << endl;
        }
        
    }

    double mx_value_mp1 = -1;
    char mx_key_mp1 = 'a';
    for(auto i : this->mp1){ // NOLINT
        if(i.second > mx_value_mp1){
            mx_value_mp1 = i.second;
            mx_key_mp1 = i.first;
        }
    }
    
    double mx_value_mp3 = -1;
    char mx_key_mp3;

    for(auto i : this->mp3){ //NOLINT
        this->mp3[i.first] = (double)(i.second) / this->size;
        if(this->mp3[i.first] > mx_value_mp3){
            mx_value_mp3 = this->mp3[i.first];
            mx_key_mp3 = i.first;
        }
    }

    int key = (mx_key_mp3 - mx_key_mp1 + 26) % 26;
    cout << "Key is: " << key << endl;
    return key;
}

string Cipher::decrypt(int key){
    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return "-1";
    }

    string decrypted = "";
    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'A' && a <= 'Z'){
            decrypted += (char)('A' + (a - 'A' - key + 26) % 26);
        }
        else{
            decrypted += a;
        }
    }

    return decrypted;
}