#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertEnd(int value) {
    Node* node = new Node{value, nullptr, nullptr};
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void deleteLast() {
    if (!tail) return;

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    } else {
        Node* del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete del;
    }
}

void viewFromFront() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    // swap next and prev
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev; // move to next (which was previous)
    }

    if (temp) head = temp->prev; 
}

int main() {
    int pilihan, nilai;

    do {
        cout << "Menu: \n1 insert (end) \n2 delete (last) \n3 view (depan) \n4 reverse & view (depan) \n0 exit\n";
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertEnd(nilai);
            break;

        case 2:
            deleteLast();
            break;

        case 3:
            viewFromFront();
            break;

        case 4:
            reverseList();
            cout << "List setelah di-reverse: ";
            viewFromFront();
            break;
        }

    } while (pilihan != 0);

    return 0;
}
