#include "../include/playfair.hpp"
#include "../include/readfile.hpp"

#include <bits/stdc++.h>
using namespace std;

PlayFair::PlayFair(string filename, string key) : key(key), filename(filename) {
    keyTable = vector<vector<char> >(5, vector<char>(5));
    generateKeyTable();
}

void PlayFair::toLowerCase(string& plain) {
    for (char& ch : plain) { // NOLINT
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
    }
}

void PlayFair::generateKeyTable() {
    vector<bool> dict(26, false);
    string processedKey;

    for (char ch : key) { // NOLINT
        if (ch == 'j') ch = 'i';
        if (!dict[ch - 'a']) {
            dict[ch - 'a'] = true;
            processedKey += ch;
        }
    }

    int row = 0, col = 0;
    for (char ch : processedKey) { // NOLINT
        keyTable[row][col++] = ch;
        if (col == 5) {
            row++;
            col = 0;
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch == 'j') continue;
        if (!dict[ch - 'a']) {
            keyTable[row][col++] = ch;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }
}

void PlayFair::search(char a, char b, int arr[]) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyTable[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyTable[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int PlayFair::mod5(int a) {
    return (a + 5) % 5;
}

string PlayFair::prepare(const string& str) {
    string preparedText;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\n') {
            preparedText += str[i];  
        } else if (str[i] == ' ') {
            preparedText += str[i];  
        } else {
            preparedText += str[i];
            if (i + 1 < str.length() && str[i] == str[i + 1]) {
                preparedText += 'x';
            }
        }
    }

    size_t letterCount = 0;
    for (char c : preparedText) { // NOLINT
        if (isalpha(c)) {
            ++letterCount;
        }
    }
    if (letterCount % 2 != 0) {
        preparedText += 'z';
    }

    return preparedText;
}

void PlayFair::encrypt(string& str) {
    int arr[4];
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ' || str[i] == '\n') continue;

        size_t j = i + 1;
        while (j < str.length() && (str[j] == ' ' || str[j] == '\n')) j++;

        if (j >= str.length()) break; 

        search(str[i], str[j], arr);

        if (arr[0] == arr[2]) {
            str[i] = keyTable[arr[0]][mod5(arr[1] + 1)];
            str[j] = keyTable[arr[0]][mod5(arr[3] + 1)];
        } else if (arr[1] == arr[3]) {
            str[i] = keyTable[mod5(arr[0] + 1)][arr[1]];
            str[j] = keyTable[mod5(arr[2] + 1)][arr[1]];
        } else {
            str[i] = keyTable[arr[0]][arr[3]];
            str[j] = keyTable[arr[2]][arr[1]];
        }
        i = j; 
    }
}

void PlayFair::decrypt(string& str) {
    int arr[4];
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ' || str[i] == '\n') continue; 

        size_t j = i + 1;
        while (j < str.length() && (str[j] == ' ' || str[j] == '\n')) j++;

        if (j >= str.length()) break;

        search(str[i], str[j], arr);

        if (arr[0] == arr[2]) {
            str[i] = keyTable[arr[0]][mod5(arr[1] - 1)];
            str[j] = keyTable[arr[0]][mod5(arr[3] - 1)];
        } else if (arr[1] == arr[3]) {
            str[i] = keyTable[mod5(arr[0] - 1)][arr[1]];
            str[j] = keyTable[mod5(arr[2] - 1)][arr[1]];
        } else {
            str[i] = keyTable[arr[0]][arr[3]];
            str[j] = keyTable[arr[2]][arr[1]];
        }
        i = j; 
    }
}

string PlayFair::postProcess(const string& str) {
    string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == 'x' && i > 0 && i < str.length() - 1 && str[i - 1] == str[i + 1]) {
            continue; 
        }
        result += str[i];
    }
    if (!result.empty() && result.back() == 'z') {
        result.pop_back();
    }
    return result;
}

string PlayFair::encrypt() {
    ReadFile file(this->filename);
    string file_content = file.read();
    toLowerCase(file_content);  
    string str = prepare(file_content); 

    encrypt(str); 

    return str;
}

string PlayFair::decrypt() {
    ReadFile file(this->filename);
    string file_content = file.read();
    toLowerCase(file_content); 
    decrypt(file_content); 

    return postProcess(file_content);
}
