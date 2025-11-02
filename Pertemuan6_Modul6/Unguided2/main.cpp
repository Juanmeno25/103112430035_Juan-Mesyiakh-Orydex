#include "Doublylist2.h"

int main() {
    List L;
    createList(L);
    infotype x;
    address P;

    // Input data awal
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

    // Cetak semua data
    printInfo(L);

    // Cari data berdasarkan nopol
    string cari;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    cin >> cari;

    address found = findElm(L, cari);
    if (found != nullptr) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan.\n";
    }

    return 0;
}
