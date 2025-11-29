#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

int main() {
    IntBinaryTree tree;

    ifstream inFile("codes.txt");
    if (!inFile) {
        cerr << "Error: could not open codes.txt" << endl;
        return 1;
    }
    string code;
    int count = 0;

    while (inFile >> code) {
        tree.insertNode(code);
        ++count;
    }

    cout << "loaded " << count << "codes into the BST." << endl;
    cout << "In order travarsal of codes:" << endl;

    tree. displayInOrder();

    return 0;
}