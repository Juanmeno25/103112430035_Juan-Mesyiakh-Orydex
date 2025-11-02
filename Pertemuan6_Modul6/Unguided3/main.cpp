#include "Doublylist3.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);
    infotype x;
    address P;

    // Input data
    for (int i = 0; i < 3; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cout << endl;
        P = alokasi(x);
        insertLast(L, P);
    }

    printInfo(L);

    // Hapus elemen berdasarkan nomor polisi
    string hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> hapus;

    address target = findElm(L, hapus);
    if (target != nullptr) {
        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P, L);
        }
        cout << "\nData dengan nomor polisi " << hapus << " berhasil dihapus.\n";
        dealokasi(P);
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    printInfo(L);
    return 0;
}
