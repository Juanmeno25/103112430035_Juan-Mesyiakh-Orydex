#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

void createTree(address &root);
address createNode(int x);
address insertNode(address root, int x);
void printInOrder(address root);

#endif
