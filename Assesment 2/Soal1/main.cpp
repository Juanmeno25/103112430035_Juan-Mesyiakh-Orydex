#include "soal1.h"

int main() {
    Node* root;
    createTree(root);

    root = insertNode(root, 60, "Rizkina Azizah", "Basic");
    insertNode(root, 50, "Hakan Ismail", "Bronze");
    insertNode(root, 65, "Olivia Saevali", "Silver");
    insertNode(root, 47, "Felix Pedrosa", "Gold");
    insertNode(root, 56, "Gamel Al Ghifari", "Platinum");
    insertNode(root, 70, "Hanif Al Faiz", "Basic");
    insertNode(root, 52, "Mutiara Fauziah", "Bronze");
    insertNode(root, 68, "Davi Ilyas", "Silver");
    insertNode(root, 81, "Abdad Mubarok", "Gold");

    cout << "--- Traversal InOrder ---" << endl;
    inOrder(root);
    cout << endl << endl;

    mostLeft(root);
    mostRight(root);
    cout << endl;

    searchByBeratBadan(root, 70);

    return 0;
}