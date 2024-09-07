#include "include/cipher.hpp"
#include "include/writefile.hpp"
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main(void) {

    clock_t start = clock();
    srand(time(0));

    map<char, double> mp;
    mp['A'] = 0.08167;
    mp['B'] = 0.01492;
    mp['C'] = 0.02782;
    mp['D'] = 0.04253;
    mp['E'] = 0.12702;
    mp['F'] = 0.02228;
    mp['G'] = 0.02015;
    mp['H'] = 0.06094;
    mp['I'] = 0.06996;
    mp['J'] = 0.00153;
    mp['K'] = 0.00772;
    mp['L'] = 0.04025;
    mp['M'] = 0.02406;
    mp['N'] = 0.06749;
    mp['O'] = 0.07507;
    mp['P'] = 0.01929;
    mp['Q'] = 0.00095;
    mp['R'] = 0.05987;
    mp['S'] = 0.06327;
    mp['T'] = 0.09056;
    mp['U'] = 0.02758;
    mp['V'] = 0.00978;
    mp['W'] = 0.02360;
    mp['X'] = 0.00150;
    mp['Y'] = 0.01974;
    mp['Z'] = 0.00074;

    Cipher cipher("data/cipher.txt", mp);
    int key = cipher.cipherattack();
    string decrypted = cipher.decrypt(key);

    cout << endl << "Decrypted text: " << decrypted << endl << endl;

    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken for execution: " << elapsed_time << " seconds" << endl << endl;
    

    return 0;
    
}