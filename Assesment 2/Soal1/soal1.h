#ifndef SOAL1_H
#define SOAL1_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

bool isEmpty(Node* root);
void createTree(Node* &root);
Node* newNode(float berat, string nama, string tier);
Node* insertNode(Node* root, float berat, string nama, string tier);
void searchByBeratBadan(Node* root, float target);
void mostLeft(Node* root);
void mostRight(Node* root);
void inOrder(Node* root);

#endif