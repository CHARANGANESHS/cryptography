#ifndef VIGENERE_HPP
#define VIGENERE_HPP

#include <string>
#include <vector>
#include <map>
using namespace std;

class VigenereCipher {
public:
    VigenereCipher(string filename);

    string decrypt();
    
private:
    vector<double> getHardcodedFrequency();
    vector<double> frequencyOnString(const string& str);
    pair<int, string> shift(const string& input, int shift);
    double getError(const vector<double>& expectedFrequency, const vector<double>& actualFrequency);
    vector<double> frequencyData;
    string filename;
};

#endif // VIGENERE_HPP
