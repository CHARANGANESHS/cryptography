#ifndef VIGENERE_HPP
#define VIGENERE_HPP

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Vigenere{
private:
    string key;
    string filename;
    map<char, int> mp1;
    map<int, char> mp2;

public:
    Vigenere(string key, string filename);
    string encrypt();
    string decrypt();

};

#endif