#ifndef CIPHER_HPP
#define CIPHER_HPP

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Cipher{
private:
    int key;
    string filename;
    map<char, int> mp1;
    map<int, char> mp2;

public:
    Cipher(int key, string filename);
    string encrypt();
    string decrypt();
};

#endif // CIPHER_HPP