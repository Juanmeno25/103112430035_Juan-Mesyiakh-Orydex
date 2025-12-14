#include <iostream>
#include "MLL1.h"
using namespace std;

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string id, string nama){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = id;
    P->isidata.namaGolongan = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string id, string nama, string habitat, bool ekor, float bobot){
    NodeChild C = new nodeChild;
    C->isidata.idHewan = id;
    C->isidata.namaHewan = nama;
    C->isidata.habitat = habitat;
    C->isidata.ekor = ekor;
    C->isidata.bobot = bobot;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void insertLastParent(listParent &L, NodeParent P){
    if(L.first == NULL){
        L.first = P;
        L.last = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild C){
    if(L.first == NULL){
        L.first = C;
        L.last = C;
    }else{
        L.last->next = C;
        C->prev = L.last;
        L.last = C;
    }
}

void printMLLStructure(listParent L){
    NodeParent P = L.first;
    int i = 1;

    while(P != NULL){
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        if(C == NULL){
            cout << "(tidak ada child)" << endl;
        }else{
            int j = 1;
            while(C != NULL){
                cout << "- Child " << j << " :" << endl;
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "  Habitat : " << C->isidata.habitat << endl;
                cout << "  Ekor : " << (C->isidata.ekor ? "1" : "0") << endl;
                cout << "  Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                j++;
            }
        }

        cout << "--------------------" << endl;
        P = P->next;
        i++;
    }
}
