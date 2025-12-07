#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};

// Deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

#endif
