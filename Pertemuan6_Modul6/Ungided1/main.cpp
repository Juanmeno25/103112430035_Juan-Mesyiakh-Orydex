#include "Doublylist1.h"

int main() {
    List L;
    createList(L);
    infotype x;
    address P;

    cout << "=== INPUT DATA KENDARAAN ===\n";
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
    return 0;
}
