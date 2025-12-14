# <h1 align="center">Laporan Praktikum Modul 13  -  Multy Linked List </h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori

Multiple Linked List adalah kumpulan beberapa Linked List yang terpisah namun dapat diakses secara bersamaan, memungkinkan pengelolaan data yang terstruktur dan efisien.

   **Multi-Linked List**  
    Multiple Linked List memungkinkan pengelolaan data secara terstruktur dengan memisahkan simpul-simpul ke dalam kelompok-kelompok yang saling terkait, sehingga memudahkan akses dan pengaturan informasi secara efisien. Dengan Multiple Linked List, setiap himpunan simpul dapat diatur secara terpisah namun tetap dapat diakses bersamaan, sehingga struktur data menjadi lebih rapi, terorganisir, dan sesuai dengan kebutuhan aplikasi.


### A. Dasar Pemograman C++<br/>
Pada dasarnya semua program memiliki algoritma yang sama, yang berbeda itu ada pada codinganya. Jika golang menggunakan import "fmt"  buat menggunakan library I/O, sedangkan C++ menggunakan #include <iostream>. Program C++ umumnya punya tiga bagian utama:
1. **Struktur Program C++**  
   Program C++ biasanya terdiri dari:  
   - `#include <iostream>` → library standar input-output  
   - `int main()` → fungsi utama yang pertama kali dijalankan  
   - `{ ... }` → blok kode perintah  

Contohnya:
```C++
#include <iostream>  
using namespace std;  

int main() {  
    cout << "Hello, World!" << endl;  
    return 0;  
}
```

2. **Tipe Data**  
a. int → Bilangan bulat (contoh: 10, -3).
b. float / double → angka desimal (contoh: 4.5, -7.1).
c. char → karakter tunggal (contoh: 'B').
d. string → teks (contoh: "Program C++").
e. bool → logika benar/salah (true / false).

3. **Operator Aritmatika** 
Untuk operator sama seperti yang ada di kalkulator:
a. + digunakan untuk penjumlahan.
b. - digunakan untuk pengurangan.
c. * digunakan untuk perkalian.
d. / digunakan untuk pembagian. 
e. % digunakan untuk sisa pembagian.

### B. Input & Output<br/>
1. **Fungsi `cin` (input)**  
   Digunakan untuk membaca masukan dari pengguna.  
   ```cpp
   int angka;
   cin >> angka;
   ```


2. **Fungsi `cout` (output)**  
   Digunakan untuk menampilkan keluaran ke layar.  
   ```cpp
   cout << "masukan angka";
   cout << "Nilai: " << angka << endl;
   ```

3. **Kombinasi Input-Output**  
   Input dapat diproses lalu langsung ditampilkan.  
   ```cpp
   cout << "Masukan angka : ";
   cin >> angka1;
   cout << "Masukan angka : ";
   cin >> angka2;
   cout << "Penjumlahan : " << angka1 + angka2 << endl;
   cout << "Pengurangan : " << angka1 - angka2 << endl;

   ```

### C. Multi Linked List

Multiple Linked List adalah struktur data yang terdiri dari beberapa Linked List terpisah, di mana setiap himpunan simpul dapat diatur secara mandiri namun tetap dapat diakses bersamaan, memungkinkan pengelolaan data yang terstruktur, rapi, dan efisien sesuai kebutuhan aplikasi.

  ```cpp
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

   ```


## Guided 

### 1. Multy Linked List
1. **Data multilist.h** 

```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <vector>
#include <string>
using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};
struct listAnak{
    NodeChild first;
    NodeChild last;
};
struct nodeParent{
    string idKategoriMakanan;
    string namaKategoriMakanan;
    listAnak daftarMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak ;
};
struct listInduk{
    NodeParent first;
    NodeParent last;
};
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void printStrukturMLL(listInduk &LInduk);

#endif

```
Multilist.h ini berisi definisi struktur data dan deklarasi fungsi yang digunakan untuk mengelola struktur data Multilist (many-to-many). File ini tidak memuat implementasi fungsi secara langsung, melainkan hanya mendefinisikan tipe data, struktur node parent (induk) dan child (anak), serta prototipe fungsi-fungsi seperti pembuatan list induk dan list anak, alokasi dan dealokasi node, penambahan dan penghapusan data parent maupun child, pencarian data anak berdasarkan ID, serta pencetakan seluruh struktur multilist. Seluruh fungsi yang dideklarasikan pada file ini nantinya akan diimplementasikan pada file .cpp terpisah.
2. **Data multilist.cpp** 

```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

```
Multilist.cpp ini berisi implementasi fungsi-fungsi dari multilist.h untuk mengelola struktur data multilist. File ini menangani pembuatan list, alokasi dan dealokasi node parent dan child, operasi tambah dan hapus data, pencarian child berdasarkan ID, serta menampilkan seluruh isi multilist. Seluruh logika pengolahan data dijalankan di file ini dan digunakan oleh main.cpp.

3. **Data Main.cpp** 

```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main(){
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl ;

    NodeChild M01 = alokasiNodeChild("M001", "Nasi Goreng");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M002", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    NodeChild S01 = alokasiNodeChild("S01", "Pudding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl ;

    printStrukturMLL(LInduk);
    cout << endl ;

    findChildByID(LInduk, "D01");
    cout << endl ;
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl ;
    deleteAfterParent(LInduk, K02);
    cout << endl ;  
    printStrukturMLL(LInduk);
    cout << endl ;
    return 0;
}
```
File main.cpp ini berfungsi sebagai program utama untuk menguji dan menjalankan struktur data multilist. Di dalamnya dibuat list induk, ditambahkan beberapa node parent (kategori makanan) dan node child (data makanan), lalu ditampilkan seluruh strukturnya. Program ini juga mendemonstrasikan fitur pencarian child berdasarkan ID serta operasi penghapusan child dan parent, sehingga memperlihatkan bagaimana fungsi-fungsi pada multilist.h dan multilist.cpp bekerja secara nyata.


## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file "MultiLL.h" :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided1/Soal1.png)
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided1/Soal12.png)
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided1/Soal13.png)
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided1/Soal14.png)

1. **Data MLL1.h** 

```C++
#ifndef MLL1_H
#define MLL1_H

#include <string>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string id, string nama);
NodeChild allocNodeChild(string id, string nama, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild C);

void printMLLStructure(listParent L);

#endif

```

2. **Data MLL1.cpp** 

```C++
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


```


3. **Data main.cpp** 

```C++
#include <iostream>
#include "MLL1.h"
using namespace std;

int main(){
    listParent L;
    createListParent(L);

    NodeParent G001 = allocNodeParent("G001", "Aves");
    NodeParent G002 = allocNodeParent("G002", "Mamalia");
    NodeParent G003 = allocNodeParent("G003", "Pisces");
    NodeParent G004 = allocNodeParent("G004", "Amfibi");
    NodeParent G005 = allocNodeParent("G005", "Reptil");

    insertLastParent(L, G001);
    insertLastParent(L, G002);
    insertLastParent(L, G003);
    insertLastParent(L, G004);
    insertLastParent(L, G005);

    insertLastChild(G001->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G002->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G002->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G002->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(L);

    return 0;
}



```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Output/Jawabanno1.png)

Program ini digunakan untuk mengelola data hewan berdasarkan golongannya menggunakan struktur data Multi Linked List dalam bahasa C++. Struktur ini terdiri dari list parent untuk menyimpan data golongan hewan dan list child untuk menyimpan data hewan pada setiap golongan. Pada file MLL1.h, didefinisikan struktur data golonganHewan, dataHewan, nodeParent, dan nodeChild beserta list penunjuknya. Setiap node parent memiliki satu list child yang berisi data hewan sesuai golongannya. Pada file MLL1.cpp, fungsi createListParent dan createListChild digunakan untuk menginisialisasi list kosong. Fungsi allocNodeParent dan allocNodeChild berfungsi untuk membuat node baru, sedangkan prosedur insertLastParent dan insertLastChild digunakan untuk menambahkan data ke akhir list agar urutan data tetap terjaga. Pada file main.cpp, program membuat beberapa golongan hewan sebagai node parent, kemudian menambahkan data hewan sebagai node child ke masing-masing golongan sesuai ketentuan soal. Terakhir, prosedur printMLLStructure dipanggil untuk menampilkan seluruh isi multi linked list ke layar. Secara keseluruhan, program ini menunjukkan cara membangun, mengisi, dan menampilkan struktur Multi Linked List dengan pemisahan kode ke dalam file header, implementasi, dan main.

### 2.Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
#### Ekspektasi output :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided2/Soal1.png)


1. **Data MLL2.h** 

```C++
#ifndef MLL2_H
#define MLL2_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild C);

void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, bool tail);

#endif


```

2. **Data MLL2.cpp** 

```C++
#include "MLL2.h"

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

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool ekor, float bobot){
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
    while(P != NULL){
        cout << "Golongan : " << P->isidata.namaGolongan << endl;
        NodeChild C = P->L_Child.first;
        while(C != NULL){
            cout << "  - " << C->isidata.namaHewan << endl;
            C = C->next;
        }
        P = P->next;
    }
}

void searchHewanByEkor(listParent L, bool tail){
    NodeParent P = L.first;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while(C != NULL){
            if(C->isidata.ekor == tail){
                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Hewan : " << C->isidata.idHewan << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
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
}


```

### 3. main.cpp

```C++
#include "MLL2.h"

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

    insertLastChild(G001->L_Child, allocNodeChild("AV001","Cendrawasih","Hutan",true,0.3));
    insertLastChild(G001->L_Child, allocNodeChild("AV002","Bebek","Air",true,2));

    insertLastChild(G002->L_Child, allocNodeChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G002->L_Child, allocNodeChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G002->L_Child, allocNodeChild("M002","Kucing","Darat",true,4));

    insertLastChild(G004->L_Child, allocNodeChild("AM001","Kodok","Sawah",false,0.2));

    printMLLStructure(L);

    cout << endl;
    searchHewanByEkor(L, false);

    return 0;
}



```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Output/Jawabanno2.png)

Pada soal 2, program ditambahkan sebuah prosedur searchHewanByEkor yang digunakan untuk melakukan pencarian data hewan berdasarkan kondisi ekor. Prosedur ini menerima parameter list parent dan nilai boolean ekor (TRUE atau FALSE). Proses pencarian dilakukan dengan cara menelusuri seluruh node parent terlebih dahulu, kemudian pada setiap node parent dilakukan penelusuran ke list child untuk memeriksa data hewan satu per satu. Jika nilai atribut ekor pada data hewan sesuai dengan nilai yang dicari (misalnya FALSE), maka data hewan tersebut akan ditampilkan ke layar.

Dengan demikian, prosedur ini menunjukkan cara melakukan searching pada struktur Multi Linked List, yaitu dengan penelusuran bertingkat dari parent ke child.
### 3. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
#### Ekspektasi output :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided3/Soal1.png)
#### (Lampirkan screenshot output hasil print setelah dilakukan delete pada laporan).
#### Ekspektasi output :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Unguided3/Soal12.png)

1. **Data MLL3.h** 

```C++
#ifndef MLL3_H
#define MLL3_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    int ekor; 
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, int ekor, float bobot);

void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild C);

void printMLLStructure(listParent L);
void searchHewanByEkor(listParent L, int tail);

#endif


```

2. **Data MLL3.cpp** 

```C++
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

```


3. **Data Main.cpp** 

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan11_Modul13/Output/Jawabanno3.png)

Program ini mengimplementasikan Multilevel Linked List (MLL) Doubly Linked List, di mana Parent Node mewakili Golongan Hewan dan menunjuk ke Child List yang berisi Data Hewan. File MLL3.h mendefinisikan struktur data hierarkis ini, sedangkan MLL3.cpp berisi fungsi-fungsi untuk inisialisasi, alokasi node, penambahan data (insertLastParent/insertLastChild), penelusuran struktur (printMLLStructure), dan pencarian spesifik (searchHewanByEkor). Di main.cpp, program membangun seluruh struktur MLL dengan memasukkan data Parent dan Child sesuai dengan skema yang diinginkan, kemudian menampilkan seluruh isi list dan mendemonstrasikan fungsi pencarian hewan berdasarkan kondisi ekor. Secara keseluruhan, program ini menunjukkan manajemen data dengan hubungan satu-ke-banyak menggunakan MLL.

## Kesimpulan
Ketiga program Multi Linked List tersebut sama-sama menunjukkan penerapan struktur data Multi Linked List untuk mengelola data hewan berdasarkan golongannya. Program pertama berfokus pada pembuatan struktur dasar Multi Linked List, yaitu node parent dan node child, serta operasi insert dan print untuk menampilkan hubungan antara golongan hewan dan data hewannya. Program kedua mengembangkan fungsionalitas dengan menambahkan operasi searching untuk menelusuri data hewan berdasarkan kondisi tertentu, yaitu hewan yang tidak memiliki ekor, dengan melakukan penelusuran pada list child di setiap node parent. Program ketiga menambahkan operasi delete pada node parent tertentu beserta seluruh data child yang terhubung, sehingga struktur Multi Linked List dapat diperbarui secara dinamis. Secara keseluruhan, ketiga program ini memperlihatkan bagaimana Multi Linked List dapat digunakan untuk merepresentasikan hubungan data bertingkat, serta mendukung operasi insert, search, delete, dan traversal data secara terstruktur dan efisien.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Fikti UMSU. (n.d.). Pengertian Linked List: Struktur Data dalam Pemrograman. Diakses 14 Desember 2025, dari https://fikti.umsu.ac.id/pengertian-linked-list-struktur-data-dalam-pemrograman/