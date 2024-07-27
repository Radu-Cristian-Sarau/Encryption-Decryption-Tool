#include "encryption.h"
#include <fstream>
#include <cctype>

using namespace std;

bool performCaesarCipher(string& content, bool encrypt) {
    int shift = encrypt ? 3 : -3;

    for (char& ch : content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a'; // Determine the base character
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base); // Perform the shift
        }
    }

    return true;
}

bool encryptFile(const string& filename, bool encrypt) {
    
    // Open the file
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    // Read the content of the file
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCaesarCipher(content, encrypt)) {
        // Create an output file and writing the modified content
        ofstream outFile(encrypt ? "encrypted_" + filename : "decrypted_" + filename); // Create the output file
        
        if (!outFile) {
            return false; // Return false if the output file cannot be created
        }

        outFile << content; // Write the modified content to the output file
        outFile.close(); // Close the output file

        return true; // Return true if the file is successfully encrypted/decrypted
    }
}