#include <iostream>
#include "encryption.h"
#include <string>
#include <fstream> 

using namespace std;

int main() {
    
    string filename;
    char mode;

    cout << "Enter the file name: " << endl;
    getline(cin >> ws, filename); // get the file name from the user

    cout << "Encrypt or Decrypt? (E/D)" << endl;
    cin >> mode; // get the mode from the user

    if (mode == 'e' || mode == 'E') {
        if (encryptFile(filename, true)) {
            cout << "File encrypted successfully." << endl;
        } else {
            cerr << "Error: Unable to perform encryption." << endl;
        }
    } else if (mode == 'd' || mode == 'D') {
        if (encryptFile(filename, false)) {
            cout << "File decrypted successfully." << endl;
        } else {
            cerr << "Error: Unable to perform decryption." << endl;
        }
    } else {
        cerr << "Error: Invalid mode selection. Use 'e' for encryption or 'd' for decryption." << endl;
    }

    return 0;
}

