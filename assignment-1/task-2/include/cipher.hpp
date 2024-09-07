#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Cipher{
private:
    string filename;
    int size;
    map<char, double> mp1;
    map<char, double> mp3;

public:
    Cipher(string filename, map<char, double> mp1);
    int cipherattack();
    string decrypt(int key);
};

#endif // CIPHER_HPP