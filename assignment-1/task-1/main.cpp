#include <bits/stdc++.h>
#include "include/cipher.hpp"
#include "include/vigenere.hpp"
#include "include/plain.hpp"
#include "include/playfair.hpp"
#include "include/writefile.hpp"
using namespace std;


int main(void){
    string filename = "process.txt";
    cout << "\n1. Cipher\t2. Vigenere\t3. PlayFair\n\n";

    cout << "Choose the type of encryption: \n";
    int choice;
    cin >> choice;
    if (choice == 1){
        cout << "Choose the encryption type: \n";
        cout << "\n1. Encrypt\t2. Decrypt\n\n";
        int user_choice;
        cin >> user_choice;
        if (user_choice == 1){
            int key;
            cout << "Enter the key: ";
            cin >> key;
            Cipher cipher(key, filename);
            string output = cipher.encrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else if (user_choice == 2){
            int key;
            cout << "Enter the key: ";
            cin >> key;
            Cipher cipher(key, filename);
            string output = cipher.decrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else{
            cout << "Invalid choice\n";
            return -1;
        }

    }
    else if(choice == 2){
        cout << "Choose the encryption type: \n";
        cout << "\n1. Encrypt\t2. Decrypt\n\n";
        int user_choice;
        cin >> user_choice;
        if (user_choice == 1){
            string key;
            cout << "Enter the key: ";
            cin >> key;
            Vigenere vigenere(key, filename);
            string output = vigenere.encrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else if (user_choice == 2){
            string key;
            cout << "Enter the key: ";
            cin >> key;
            Vigenere vigenere(key, filename);
            string output = vigenere.decrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else{
            cout << "Invalid choice\n";
            return -1;
        }
    }
    else if(choice == 3){
        cout << "Choose the encryption type: \n";
        cout << "\n1. Encrypt\t2. Decrypt\n\n";
        int user_choice;
        cin >> user_choice;
        if (user_choice == 1){
            string key;
            cout << "Enter the key: ";
            cin >> key;
            PlayFair playfair(filename, key);
            string output = playfair.encrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else if (user_choice == 2){
            string key;
            cout << "Enter the key: ";
            cin >> key;
            PlayFair playfair(filename, key);
            string output = playfair.decrypt();
            cout << output << endl;
            WriteFile file(filename);
            file.write(output);
        }
        else{
            cout << "Invalid choice\n";
            return -1;
        }
    }
    else{
        cout << "Invalid choice\n";
        return -1;
    }




}