#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi menambah node di akhir
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

// Menampilkan isi linked list
void display(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Mendapatkan node tengah (antara start dan end)
Node* getMiddle(Node* start, Node* end, int& index) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start->next;
    index = 0;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
            index++;
        }
    }
    return slow;
}

// Binary Search di linked list
Node* binarySearch(Node* head, int target) {
    Node* start = head;
    Node* end = nullptr;
    int iter = 1;

    cout << "\nProses Pencarian:\n";
    while (start != end) {
        int index = 0;
        Node* mid = getMiddle(start, end, index);
        if (!mid) break;

        cout << "Iterasi " << iter++ << ": Mid = " << mid->data 
             << " (indeks tengah)";

        if (mid->data == target) {
            cout << " - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << target << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << mid << endl;
            cout << "Data node: " << mid->data << endl;
            if (mid->next)
                cout << "Node berikutnya: " << mid->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return mid;
        } 
        else if (mid->data < target) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next;
        } 
        else {
            cout << " -> Cari di bagian kiri\n";
            end = mid;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << target << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST\n";

    // Membuat linked list 
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    display(head);

    // Tes 1
    int target = 40;
    cout << "Mencari nilai: " << target << endl;
    binarySearch(head, target);

    // Tes 2
    target = 25;
    cout << "\nMencari nilai: " << target << endl;
    binarySearch(head, target);

    return 0;
}