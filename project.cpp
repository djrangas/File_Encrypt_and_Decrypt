#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string& filename, int key);
void decryptFile(const string& filename, int key);

int main() {
    int choice, key;
    string filename;

    do {
        cout << "1. Encrypt File\n";
        cout << "2. Decrypt File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter filename to encrypt: ";
            cin >> filename;
            cout << "Enter key (shift value): ";
            cin >> key;
            encryptFile(filename, key);
        } 
        else if (choice == 2) {
            cout << "Enter filename to decrypt: ";
            cin >> filename;
            cout << "Enter key (shift value): ";
            cin >> key;
            decryptFile(filename, key);
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        } 
        else {
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}

void encryptFile(const string& filename, int key) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for encryption.\n";
        return;
    }

    ofstream outFile("encrypted_" + filename);
    char ch;

    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset + key) % 26 + offset;
        }
        outFile.put(ch);
    }

    cout << "File encrypted successfully as 'encrypted_" << filename << "'\n";
    
    inFile.close();
    outFile.close();
}

void decryptFile(const string& filename, int key) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for decryption.\n";
        return;
    }

    ofstream outFile("decrypted_" + filename);
    char ch;

    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            ch = (ch - offset - key + 26) % 26 + offset;
        }
        outFile.put(ch);
    }

    cout << "File decrypted successfully as 'decrypted_" << filename << "'\n";
    
    inFile.close();
    outFile.close();
}
