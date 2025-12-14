#include "MLL3.h"

int main(){
    listParent L;
    createListParent(L);

    NodeParent G001 = allocNodeParent("G001","Aves");
    NodeParent G002 = allocNodeParent("G002","Mamalia");
    NodeParent G003 = allocNodeParent("G003","Pisces");
    NodeParent G004 = allocNodeParent("G004","Amfibi"); 
    NodeParent G005 = allocNodeParent("G005","Reptil");

    insertLastParent(L, G001);
    insertLastParent(L, G002);
    insertLastParent(L, G003); 
    insertLastParent(L, G004); 
    insertLastParent(L, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",1,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",1,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",1,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",0,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",1,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",0,0.2));

    cout << "======= TAMPILAN STRUKTUR MLL =======" << endl;
    printMLLStructure(L);

    cout << endl;

    searchHewanByEkor(L, 0);

    return 0;
}