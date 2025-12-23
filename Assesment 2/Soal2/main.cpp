#include "soal2.h"

int main() {
    ListParent L;
    createListParent(L);

    NodeParent *g4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(L, g4);
    NodeParent *g3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(L, g3);
    NodeParent *g2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(L, g2);
    NodeParent *g1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(L, g1);

    insertLastChild(g1->child, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
    insertLastChild(g2->child, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(g2->child, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
    insertLastChild(g3->child, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
    insertLastChild(g4->child, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(g4->child, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    printStrukturMLL(L);
    cout << endl;

    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl;

    NodeParent *del;
    deleteAfterParent(L, L.first, del); // Menghapus G002 setelah G001
    
    printStrukturMLL(L);

    return 0;
}