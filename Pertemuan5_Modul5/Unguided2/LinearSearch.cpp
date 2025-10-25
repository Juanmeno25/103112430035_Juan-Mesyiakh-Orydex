#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

// Tambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Tampilkan isi linked list
void display(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Linear Search
Node* linearSearch(Node* head, int target) {
    Node* temp = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";

    while (temp) {
        cout << "Memeriksa node " << index << ": " << temp->data << " ";
        if (temp->data == target) {
            cout << "(SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << target << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return temp;
        } else {
            cout << "(tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << target << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // Membuat linked list (data terurut)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    display(head);

    // Pencarian pertama
    int target = 30;
    cout << "Mencari nilai: " << target << endl;
    linearSearch(head, target);

    // Pencarian kedua
    target = 25;
    cout << "\nMencari nilai: " << target << endl;
    linearSearch(head, target);

    return 0;
}