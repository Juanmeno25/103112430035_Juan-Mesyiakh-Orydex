#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* head = nullptr;

void insertName(const string& name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }
}

void deleteName(const string& name) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) head = temp->next;
    else prev->next = temp->next;

    delete temp;
}

void viewList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

int countEven() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->name.length() % 2 == 0) count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int pilihan;
    string nama;

    do {
        cout << "Menu: \n1 insert, \n2 delete, \n3 view, \n4 hitung genap, \n0 exit\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            cout << "Masukkan nama: ";
            getline(cin, nama);
            insertName(nama);
            break;

        case 2:
            cout << "Masukkan nama untuk delete: ";
            getline(cin, nama);
            deleteName(nama);
            break;

        case 3:
            viewList();
            break;

        case 4:
            cout << "Jumlah nama dengan huruf genap: " << countEven() << endl;
            break;
        }
    } 
    while (pilihan != 0);

    return 0;
}
