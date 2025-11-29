#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

int main() {
    IntBinaryTree tree;
    
    tree.insertNode("F6Mq5iOx");
    tree.insertNode("GZxYmRnt");
    tree.insertNode("AKtWQ1Zt");
    tree.insertNode("8BVNHPxI");
    tree.insertNode("5oQfdrRs");

    cout << "In order traversal of codes:" << endl;
    tree.displayInOrder();

    cout << "Searching for codes" << endl;
    cout << "Search F6Mq5iOx: " << (tree.searchNode("F6Mq5iOx") ? "found" : "not found") << endl;
    cout << "Search GZxYmRnt: " << (tree.searchNode("GZxYmRnt") ? "found" : "not found") << endl;
    cout << "Search XXXX: " << (tree.searchNode("XXXX") ? "found" : "not found") << endl;

    cout << "deleting code AKtWQ1Zt:" << endl;
    tree.remove("AKtWQ1Zt");
    tree.displayInOrder();

    return 0;
}