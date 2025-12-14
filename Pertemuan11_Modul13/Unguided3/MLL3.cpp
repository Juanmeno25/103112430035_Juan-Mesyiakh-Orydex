#include "MLL3.h"

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, int ekor, float bobot){
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
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
    int parentCount = 1;

    while(P != NULL){
        cout << "=== Parent " << parentCount << " ===" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        NodeChild C = P->L_Child.first;
        int childCount = 1;

        if(C == NULL){
            cout << "(tidak ada child)" << endl;
        }

        while(C != NULL){
            cout << "- Child " << childCount << " :" << endl;
            cout << " ID Hewan : " << C->isidata.idHewan << endl;
            cout << " Nama Hewan : " << C->isidata.namaHewan << endl;
            cout << " Habitat : " << C->isidata.habitat << endl;
            cout << " Ekor : " << C->isidata.ekor << endl;
            cout << " Bobot : " << C->isidata.bobot << endl;

            C = C->next;
            childCount++;
        }
        cout << "------------------------------------------" << endl;

        P = P->next;
        parentCount++;
    }
}

void searchHewanByEkor(listParent L, int tail){
    NodeParent P = L.first;
    bool found = false;

    cout << "--- Hasil Pencarian Hewan dengan Ekor: " << tail << " ---" << endl;
    cout << "--------------------------------------------" << endl;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while(C != NULL){
            if(C->isidata.ekor == tail){
                found = true;
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << C->isidata.ekor << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Golongan : " << P->isidata.idGolongan << endl;
                cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;
                cout << "--------------------------------------------" << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
    }
    if (!found) {
        cout << "Tidak ada hewan yang ditemukan dengan kondisi ekor: " << tail << endl;
    }
    cout << "--------------------------------------------" << endl;
}