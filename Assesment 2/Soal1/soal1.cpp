#include "soal1.h"

bool isEmpty(Node* root) {
    return root == NULL;
}

void createTree(Node* &root) {
    root = NULL;
}

Node* newNode(float berat, string nama, string tier) {
    Node *nodeBaru = new Node();
    nodeBaru->beratBadan = berat;
    nodeBaru->namaMember = nama;
    nodeBaru->tierMember = tier;
    nodeBaru->left = nodeBaru->right = NULL;
    return nodeBaru;
}

Node* insertNode(Node* root, float berat, string nama, string tier) {
    if (root == NULL) return newNode(berat, nama, tier);
    if (berat < root->beratBadan) 
        root->left = insertNode(root->left, berat, nama, tier);
    else if (berat > root->beratBadan) 
        root->right = insertNode(root->right, berat, nama, tier);
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

void mostLeft(Node* root) {
    Node* curr = root;
    while (curr && curr->left) curr = curr->left;
    if (curr) cout << "Node MostLeft : " << curr->beratBadan << endl;
}

void mostRight(Node* root) {
    Node* curr = root;
    while (curr && curr->right) curr = curr->right;
    if (curr) cout << "Node MostRight : " << curr->beratBadan << endl;
}

void searchByBeratBadan(Node* root, float target) {
    Node* curr = root;
    Node* parent = NULL;
    Node* sibling = NULL;

    while (curr != NULL && curr->beratBadan != target) {
        parent = curr;
        if (target < curr->beratBadan) {
            curr = curr->left;
            sibling = parent->right;
        } else {
            curr = curr->right;
            sibling = parent->left;
        }
    }

    if (curr == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    cout << "Data ditemukan didalam BST!" << endl;
    cout << "--- Data Node Yang Dicari ---" << endl;
    cout << "Nama Member : " << curr->namaMember << endl;
    cout << "Berat Badan : " << curr->beratBadan << endl;
    cout << "Tier Member : " << curr->tierMember << endl;
    cout << "-----------------------------" << endl;

    cout << "--- Data Parent ---" << endl;
    if (parent) {
        cout << "Nama Member : " << parent->namaMember << endl;
        cout << "Berat Badan : " << parent->beratBadan << endl;
        cout << "Tier Member : " << parent->tierMember << endl;
    } else {
        cout << "Tidak Memiliki Parent" << endl;
    }
    cout << "-----------------------------" << endl;

    if (sibling) 
        cout << "Data Sibling : " << sibling->namaMember << " [" << sibling->beratBadan << "]" << endl;
    else 
        cout << "Tidak Memiliki Sibling" << endl;
    cout << "-----------------------------" << endl;

    cout << "--- Data Child Kiri ---" << endl;
    if (curr->left) {
        cout << "Nama Member : " << curr->left->namaMember << endl;
        cout << "Berat Badan : " << curr->left->beratBadan << endl;
        cout << "Tier Member : " << curr->left->tierMember << endl;
    } else cout << "Tidak Memiliki Child Kiri" << endl;
    cout << "-----------------------------" << endl;

    cout << "--- Data Child Kanan ---" << endl;
    if (curr->right) {
        cout << "Nama Member : " << curr->right->namaMember << endl;
        cout << "Berat Badan : " << curr->right->beratBadan << endl;
        cout << "Tier Member : " << curr->right->tierMember << endl;
    } else cout << "Tidak Memiliki Child Kanan" << endl;
    cout << "-----------------------------" << endl;
}