#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <string>

class IntBinaryTree {
private:

struct TreeNode {
std::string value;
TreeNode *left;
TreeNode *right;
};

TreeNode *root;

void insert(TreeNode *&, TreeNode *&);
void destroySubTree(TreeNode *);
void deleteNode(const std::string &, TreeNode *&);
void makeDeletion(TreeNode *&);
void displayInOrder(TreeNode *) const;
void displayPreOrder(TreeNode *) const;
void displayPostOrder(TreeNode *) const;
public:

IntBinaryTree() { root = nullptr; }

~IntBinaryTree() { destroySubTree(root); }

void insertNode(const std::string &);
bool searchNode(const std::string &);
void remove(const std::string &);

void displayInOrder() const { displayInOrder(root); }
void displayPreOrder() const { displayPreOrder(root); }
void displayPostOrder() const { displayPostOrder(root); }
};

#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
if (!nodePtr)
nodePtr = newNode;
else if (newNode->value < nodePtr->value)
insert(nodePtr->left, newNode);
else
insert(nodePtr->right, newNode);
}

void IntBinaryTree::insertNode(const std::string &code) {
TreeNode *newNode; 
newNode = new TreeNode;
newNode->value = code;
newNode->left = newNode->right = nullptr;

insert(root, newNode);
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
if (nodePtr) {
if (nodePtr->left)
destroySubTree(nodePtr->left);
if (nodePtr->right)
destroySubTree(nodePtr->right);
delete nodePtr;
}
}

bool IntBinaryTree::searchNode(const std::string &code) {
TreeNode *nodePtr = root;
while (nodePtr) {
if (nodePtr->value == code)
return true;
else if (code < nodePtr->value)
nodePtr = nodePtr->left;
else
nodePtr = nodePtr->right;
}
return false;
}

void IntBinaryTree::remove(const std::string &code) {
deleteNode(code, root);
}

void IntBinaryTree::deleteNode(const std::string &code, TreeNode *&nodePtr) {
    if (!nodePtr)
    return;
if (code < nodePtr->value)
deleteNode(code, nodePtr->left);
else if (code > nodePtr->value)
deleteNode(code, nodePtr->right);
else
makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {

TreeNode *tempNodePtr;
if (!nodePtr)
cout << "Cannot delete empty node.\n";
else if (!nodePtr->right) {
tempNodePtr = nodePtr;
nodePtr = nodePtr->left;
delete tempNodePtr;
} else if (!nodePtr->left) {
tempNodePtr = nodePtr;
nodePtr = nodePtr->right;
delete tempNodePtr;
}

else {

tempNodePtr = nodePtr->right;

while (tempNodePtr->left)

tempNodePtr->left = nodePtr->left;
tempNodePtr = nodePtr;

nodePtr = nodePtr->right;
delete tempNodePtr;
}
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
if (nodePtr) {
displayInOrder(nodePtr->left);
cout << nodePtr->value << endl;
displayInOrder(nodePtr->right);
}
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
if (nodePtr) {
cout << nodePtr->value << endl;
displayPreOrder(nodePtr->left);
displayPreOrder(nodePtr->right);
}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
if (nodePtr) {
displayPostOrder(nodePtr->left);
displayPostOrder(nodePtr->right);
cout << nodePtr->value << endl;
}
}
#endif // INTBINARYTREE_H