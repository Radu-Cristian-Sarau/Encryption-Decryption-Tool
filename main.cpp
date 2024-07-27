#include <iostream>
#include "encryption.h"
#include <string>
#include <fstream> 

using namespace std;

int main() {
    
    string filename;
    char mode;

    cout << "Enter the file name";
    getline(cin >> ws, filename); // get the file name from the user

    cout << "Encrypt or Decrypt? (E/D)";
    cin >> mode; // get the mode from the user

    if (mode == 'e' || mode == 'E') {
        
    }

    return 0;
}

