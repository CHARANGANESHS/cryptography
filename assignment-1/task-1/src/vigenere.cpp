#include "../include/vigenere.hpp"
#include "../include/readfile.hpp"

using namespace std;

Vigenere::Vigenere(string key, string filename){
    this->key = key;
    this->filename = filename;
    for(int i = 0; i < 26; i++){
        mp1['a' + i] = i;
        mp2[i] = 'a' + i;
    }
}

string Vigenere::encrypt(){
    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return "-1";
    }

    string key = this->key;
    string encrypted_text = "";
    int key_index = 0;
    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'a' && a <= 'z'){
            int index = mp1[a];
            int key_value = mp1[key[key_index]];
            index = (index + key_value) % 26;
            encrypted_text += mp2[index];
            key_index = (key_index + 1) % key.size();
        }
        else{
            encrypted_text += a;
        }
    }

    return encrypted_text;
}

string Vigenere::decrypt(){

    ReadFile file(this->filename);
    string file_content = file.read();

    if (file_content == "-1"){
        cout << "File not found" << endl;
        return "-1";
    }

    string key = this->key;
    string decrypted_text = "";
    int key_index = 0;
    for(int i = 0; i < file_content.size(); i++){
        char a = file_content[i];
        if (a >= 'a' && a <= 'z'){
            int index = mp1[a];
            int key_value = mp1[key[key_index]];
            index = (index - key_value + 26) % 26;
            decrypted_text += mp2[index];
            key_index = (key_index + 1) % key.size();
        }
        else{
            decrypted_text += a;
        }
    }

    return decrypted_text;
}