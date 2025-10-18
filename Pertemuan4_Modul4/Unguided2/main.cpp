#include "Singlylist.h"

int main() {
    List L;
    address P;
    createList(L);

    // Membuat list: 9 12 8 0 2
    int data[] = {2, 0, 8, 12, 9};
    for (int i = 0; i < 5; i++)
        insertFirst(L, alokasi(data[i]));

    printInfo(L); // Output: 9 12 8 0 2

    // Hapus node 9 (deleteFirst)
    deleteFirst(L, P);
    dealokasi(P);

    // Hapus node 2 (deleteLast)
    deleteLast(L, P);
    dealokasi(P);

    // Hapus node 8 (deleteAfter)
    deleteAfter(L.first, P);
    dealokasi(P);

    printInfo(L); // Output: 12 0
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    // Hapus seluruh node
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
