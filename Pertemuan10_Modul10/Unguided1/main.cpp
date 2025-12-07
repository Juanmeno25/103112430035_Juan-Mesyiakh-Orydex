#include "Tree1.h"

int main() {
    cout << "Hello world!" << endl;

    address root;
    createTree(root);

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    printInOrder(root);

    return 0;
}
