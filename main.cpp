#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

void loadFromFile(const string &filename, IntBinaryTree &tree) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file '" << filename << "'." << endl;
        return;
    }
    string code;
    int count = 0

    while (inFile >> code) {
        tree.insertNode(code);
        ++count;
    }

    cout << "Loaded " << count << " codes from " << filename << "." << endl;

}

void showMenu() {
    cout << "\n===== Code BST Menu =====\n";
    cout << "1. Display all codes (in-order)\n";
    cout << "2. Search for a code\n";
    cout << "3. Add a new code\n";
    cout << "4. Delete a code\n";
    cout << "5. Modify a code\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}


int main() {
    IntBinaryTree tree;

    int choice = 0;
    string code, oldCode, newCode;

    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
        case 1:
            cout << "\nCodes in BST:\n";
            tree.displayInOrder();
            break;
            
        case 2:
            cout << "Enter code to search: ";
            cin >> code;
            if(tree.searchNode(code))
                cout << "Code '" << code << "' FOUND.\n";
            else
                cout << "Code '" << code << "' NOT found.\n";
            break;
        case 3:
            cout << "Enter code to add: ";
            cin >> code;
            if (tree.searchNode(code)) {
                cout << "Code already exists.\n";
            } else {
                tree.insertNode(code);
                cout << "Code '" << code << "' added.\n";
            }
            break;
        case 4:
            cout << "Enter code to delete: ";
            cin >> code;
            if (tree.searchNode(code)) {
                tree.remove(code);
                cout << "Code '" << code << "' deleted.\n";
            } else {
                cout << "Code '" << code << "' not found.\n";
            }
            break;
        case 5:
        cout << "Enter existing code to modify: ";
        cin >> oldCode;
        if (!tree.searchNode(oldCode)) {
            cout << "Code '" << oldCode << "' not found.\n";
            
        }
        }
    }

    return 0;
}