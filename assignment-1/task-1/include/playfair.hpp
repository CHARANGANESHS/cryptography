#ifndef PLAYFAIR_HPP
#define PLAYFAIR_HPP

#include <iostream>
#include <vector>
using namespace std;

class PlayFair {
private:
    string key;
    string filename;
    vector<vector<char> > keyTable;

    void toLowerCase(string& plain);
    string removeSpaces(const string& plain);
    void generateKeyTable();
    void search(char a, char b, int arr[]);
    int mod5(int a);
    string prepare(const string& str);
    void encrypt(string& str);
    void decrypt(string& str);
    string postProcess(const string& str);

public:
    PlayFair(string filename, string key);
    string encrypt();
    string decrypt();
};

#endif