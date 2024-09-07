#include "include/vigenere.hpp"
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main(void) {



  clock_t start = clock();
  srand(time(0));



  VigenereCipher vigenere("./data/vigenere.txt");
  string result = vigenere.decrypt();
  cout << result << endl;
  
  clock_t end = clock();
  double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
  cout << "Time taken for execution: " << elapsed_time << " seconds" << endl << endl;

  return 0;
}