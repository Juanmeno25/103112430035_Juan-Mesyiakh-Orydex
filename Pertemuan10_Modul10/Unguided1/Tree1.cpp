#include "Tree1.h"

void createTree(address &root) {
    root = NULL;
}

address createNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

address insertNode(address root, int x) {
    if (root == NULL) {
        return createNode(x);
    }
    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else {
        root->right = insertNode(root->right, x);
    }
    return root;
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}
