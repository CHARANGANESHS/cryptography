#ifndef PLAIN_HPP
#define PLAIN_HPP

#include <bits/stdc++.h>
using namespace std;


class Plain{
private:
    string filename;
    string key;
    map<char, char> mp1;
    map<char, char> mp2;

public:
    Plain(string filename, string key);
    string encrypt();
    string decrypt();
};

#endif // PLAIN_HPP