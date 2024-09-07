#include "../include/vigenere.hpp"
#include "../include/readfile.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
// Hardcoded frequency data
const vector<double> HARD_CODED_FREQUENCIES{
    // NOLINT
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966,
    0.153, 0.772, 4.025, 2.406, 6.749,  7.507, 1.929, 0.095, 5.987,
    6.317, 9.056, 2.758, 0.978, 2.560,  0.150, 1.929, 0.095};

VigenereCipher::VigenereCipher(string filename)
    : frequencyData(HARD_CODED_FREQUENCIES) {
  this->filename = filename;
}

vector<double> VigenereCipher::getHardcodedFrequency() { return frequencyData; }

vector<double> VigenereCipher::frequencyOnString(const string &str) {
  vector<double> frequency(26, 0);
  int totalChars = 0;

  for (char ch : str) { // NOLINT
    if (isalpha(ch)) {
      ch = tolower(ch);
      frequency[ch - 'a']++;
      totalChars++;
    }
  }

  for (int i = 0; i < 26; ++i) {
    frequency[i] = (frequency[i] * 100) / totalChars;
  }

  return frequency;
}

pair<int, string> VigenereCipher::shift(const string &input, int shifts) {
  string output;
  for (char ch : input) { // NOLINT
    if (isalpha(ch)) {
      char base = islower(ch) ? 'a' : 'A';
      char c = char(base + ((ch - base + shifts) % 26));
      output += c;
    } else {
      output += ch;
    }
  }
  return make_pair(shifts, output);
}

double VigenereCipher::getError(const vector<double> &expectedFrequency,
                                const vector<double> &actualFrequency) {
  double error = 0;
  for (int i = 0; i < 26; ++i) {
    error += abs(expectedFrequency[i] - actualFrequency[i]);
  }
  return error;
}

string VigenereCipher::decrypt() {
  ReadFile file(this->filename);
  string cipherText = file.read();
  vector<vector<int> > allShifts;
  double overallMinError = numeric_limits<double>::infinity();
  string finalOutput;

  for (int keywordLength = 1; keywordLength <= 6; ++keywordLength) {
    vector<string> substrings(keywordLength, "");

    for (size_t i = 0; i < cipherText.size(); ++i) {
      substrings[i % keywordLength] += cipherText[i];
    }

    vector<int> shifts;

    for (size_t i = 0; i < substrings.size(); ++i) {
      double minError = numeric_limits<double>::infinity();
      int bestShift = 0;

      for (int shiftss = 0; shiftss < 26; ++shiftss) {
        auto [_, shiftedString] = shift(substrings[i], shiftss); // NOLINT
        auto frequencyList = frequencyOnString(shiftedString);   // NOLINT
        double error = getError(frequencyData, frequencyList);

        if (error < minError) {
          minError = error;
          bestShift = shiftss;
        }
      }
      shifts.push_back((26 - bestShift) + 26 % 26);
    }

    allShifts.push_back(shifts);
  }

  for (const auto &shifts : allShifts) { // NOLINT
    string currentOutput;
    for (size_t i = 0; i < cipherText.size(); ++i) {

      currentOutput += char(
          ((cipherText[i] - 'A' - shifts[i % shifts.size()] + 26) % 26) + 'A');
    }

    double currentError =
        getError(frequencyData, frequencyOnString(currentOutput));
    if (currentError < overallMinError) {
      overallMinError = currentError;
      finalOutput = currentOutput;
    }
  }

  return finalOutput;
}
