# <h1 align="center">Laporan Praktikum Modul 6  -  DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori

Doubly Linked List (DLL) merupakan salah satu struktur data linier yang tersusun atas sekumpulan node yang saling terhubung satu sama lain. Setiap node dalam DLL memiliki tiga bagian utama, yaitu data yang menyimpan informasi, pointer yang menunjuk ke node berikutnya (next), dan pointer yang menunjuk ke node sebelumnya (prev). Berbeda dengan Single Linked List (SLL) yang hanya memiliki satu pointer untuk menghubungkan node ke node berikutnya, Doubly Linked List memiliki hubungan dua arah sehingga setiap node dapat mengetahui baik penerus maupun pendahulunya.

   **Dubly Linked List**  
   Doubly Linked List adalah struktur data yang terdiri dari kumpulan elemen yang disebut node, di mana setiap node saling terhubung melalui dua pointer, yaitu pointer ke node sebelumnya (prev) dan pointer ke node berikutnya (next). Setiap node juga menyimpan data atau informasi yang menjadi isi dari elemen tersebut. Dengan adanya dua pointer ini, Doubly Linked List memungkinkan proses penelusuran dilakukan ke dua arah, baik maju ke depan maupun mundur ke belakang.




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
### C. Double Liinked List
Doubly Linked List adalah salah satu jenis struktur data yang berbentuk rangkaian node, di mana setiap node saling terhubung secara dua arah. Setiap node di dalam Doubly Linked List memiliki tiga komponen, yaitu data yang menyimpan informasi, pointer next yang menunjuk ke node berikutnya, dan pointer prev yang menunjuk ke node sebelumnya. Dengan adanya dua pointer tersebut, daftar ini dapat ditelusuri dari dua arah, baik dari awal ke akhir maupun dari akhir ke awal.


   ```cpp
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 

   ```
## Guided 

### 1. List Makanan
1. **Data listMakanan.h** 

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

```
File ini berisi struktur data dan deklarasi fungsi untuk doubly linked list makanan. Terdapat tipe data makanan, node, dan linkedlist, serta fungsi untuk membuat list, menambah, menghapus, menampilkan, dan memperbarui data. File ini hanya mendeklarasikan apa yang tersedia, sedangkan implementasinya ada di file .cpp terpisah.

2. **Data listMakanan.cpp** 

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodeNext) tidak valid!" << endl;
        }
    }
}
```
File ini berisi implementasi fungsi-fungsi yang telah dideklarasikan di listMakanan.h. Di dalamnya terdapat cara kerja untuk membuat list, menambah node (awal, akhir, sebelum, sesudah), menampilkan data, serta memperbarui isi node pada linked list makanan.Setiap fungsi mengatur hubungan antar node (next dan prev) agar list tetap terhubung dua arah (doubly linked list).

3. **Data Main.cpp** 

```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
    

}
```
File main.cpp adalah program utama yang menggunakan linked list buah dari listBuah.h. Program ini membuat list kosong, membuat beberapa node buah, menambahkan node ke list dengan insertFirst, insertLast, dan insertAfter, lalu menampilkan isi list dan jumlah node. Selanjutnya, program memperbarui data pada node pertama, terakhir, dan setelah node tertentu, kemudian menampilkan kembali isi list dan jumlah node setelah update. Intinya, file ini mendemonstrasikan cara membuat, menambah, memperbarui, dan menampilkan data pada linked list buah.

### 2. Doubly Linked List
1. **Data Doublylist.h** 

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
#define Nil NULL

using namespace std;

// Tipe data info (kendaraan)
struct kendaraan { //struktur untuk menyimpan info kendaraan
    string nopol; 
    string warna;
    int thnBuat;
};
typedef kendaraan infotype;

// Tipe address dan elemen list
typedef struct ElmList *address;
struct ElmList {
    infotype info; // info kendaraan
    address next;
    address prev;
};

// Tipe list
struct List {
    address first; //pointer ke elemen pertama
    address last;  //pointer ke elemen terakhir
};

// Prototypes
void CreateList(List &L); //ngebuat list kosong
address alokasi(infotype x); //alokasi elemen baru/nambah elemen baru
void dealokasi(address &P); //dealokasi elemen/hapus elemen

// Insert Last
void insertLast(List &L, address P);

// Searching
address findElm(List L, string nopol);

// Delete
void deleteByNopol(List &L, string nopol);

// Tampilkan isi list
void printInfo(List L);

#endif 
```
File ini berisi struktur data dan deklarasi fungsi untuk doubly linked list kendaraan. Di dalamnya terdapat tipe data kendaraan, ElmList, dan List, serta fungsi-fungsi untuk membuat list, menambah elemen, menghapus elemen, mencari data berdasarkan nomor polisi, dan menampilkan isi list. File ini hanya berisi deklarasi dan rancangan struktur data, sedangkan cara kerjanya akan diimplementasikan di file .cpp terpisah.
2. **Data Doublylist.cpp** 

```C++
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { //blm ada elemen
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { //fs alokasi elemen baru
    address P = new ElmList; //alokasi memori untuk elemen baru
    P->info = x; //mengisi bagian info dengan data x
    P->next = Nil; //ini jadi nill karena gak terhubung ke list manapun
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; //menghapus elemen yang ditunjuk oleh P dan mengembalikan memori ke sistem
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { // List kosong
        L.first = P; // elemen pertama dan terakhir sama dengan P
        L.last = P;
    } else { // List ada isi
        P->prev = L.last; // prev P menunjuk ke elemen terakhir saat ini
        (L.last)->next = P; // next elemen terakhir saat ini menunjuk ke P
        L.last = P; // update last menjadi P
    }
}

// Searching
address findElm(List L, string nopol) {
    address P = L.first; // mulai dari elemen pertama
    while (P != Nil) {
        //Bandingkan nopol yang dicari dengan nopol di elemen saat ini
        if (P->info.nopol == nopol) {
            return P; // Ketemu
        }
        P = P->next; // Lanjut ke elemen berikutnya kalau g cocok
    }
    return Nil; // Tidak ketemu
}

// Delete
void deleteByNopol(List &L, string nopol) {
    // Cari elemen dengan nopol yang sesuai
    address P = findElm(L, nopol);
    if (P == Nil) { // Tidak ditemukan
        cout << "Nomor polisi " << nopol << " tidak ditemukan.\n";
    } else { // Ditemukan
        if (P == L.first && P == L.last) { // Kasus 1: Hanya 1 elemen di list
            L.first = Nil; L.last = Nil;
        } else if (P == L.first) { // Kasus 2: Hapus elemen pertama tapi bukan satu-satunya
            L.first = P->next; // update first ke elemen berikutnya
            (L.first)->prev = Nil; // update prev elemen pertama barumenjadi nil
        } else if (P == L.last) { // Kasus 3: Hapus elemen terakhir
            L.last = P->prev; // update last ke elemen sebelumnya
            (L.last)->next = Nil; P->prev = Nil; // update next elemen terakhir baru menjadi nil
        } else { // Kasus 4: Hapus elemen di tengah
            address Prec = P->prev; // elemen sebelum P
            address Succ = P->next; // elemen setelah P
            Prec->next = Succ; Succ->prev = Prec; // hubungkan Prec ke Succ
            P->next = Nil; P->prev = Nil; // putuskan hubungan P dari list
        }
        dealokasi(P); // dealokasi elemen P
        cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus.\n";
    }
}


void printInfo(List L) { //menampilkan isi list
    address P = L.first; //mulai dari elemen pertama
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi: " << P->info.nopol << endl;
            cout << "warna    : " << P->info.warna << endl;
            cout << "tahun    : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}
```
File ini berisi implementasi fungsi-fungsi dari deklarasi yang ada di Doublylist.h. Di dalamnya terdapat cara kerja untuk membuat list kosong, menambah elemen di akhir list, mencari data kendaraan berdasarkan nomor polisi, menghapus data tertentu, dan menampilkan seluruh isi list. File ini menjelaskan bagaimana hubungan antar elemen (next dan prev) dikelola agar list tetap terhubung dua arah.

3. **Data Main.cpp** 

```C++
#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan

    data = {"D001", "hitam", 90}; P = alokasi(data); insertLast(L, P);
    data = {"D003", "putih", 70}; P = alokasi(data); insertLast(L, P);
    data = {"D004", "kuning", 90}; P = alokasi(data); insertLast(L, P);

    cout << "DATA LIST AWAL" << endl;
    printInfo(L);


    string cariNopol = "D001";
    cout << "MENCARI NOPOL " << cariNopol << " -" << endl;
    address found = findElm(L, cariNopol); //Manggil fungsi pencarian di Doublylist.cpp
    if (found != Nil) { // Ketemu
        cout << "Ditemukan: " << found->info.nopol << ", Warna: " << found->info.warna << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    string hapusNopol = "D003";
    cout << "MENGHAPUS NOPOL " << hapusNopol << " -" << endl;
    deleteByNopol(L, hapusNopol); //Manggil fungsi delete di Doublylist.cpp
    cout << endl;

    cout << "DATA LIST SETELAH HAPUS" << endl;
    printInfo(L);

    // Contoh delete elemen pertama
    cout << "MENGHAPUS ELEMEN PERTAMA " << endl;
    deleteByNopol(L, L.first->info.nopol); //Menghapus elemen pertama
    cout << endl;
    printInfo(L);


    return 0;
}
```
File ini merupakan program utama yang digunakan untuk menjalankan dan menguji fungsi-fungsi dari Doublylist. Di dalamnya dibuat list kendaraan, ditambahkan beberapa data menggunakan fungsi insertLast, kemudian dilakukan pencarian data berdasarkan nomor polisi, penghapusan data tertentu, serta penampilan isi list sebelum dan sesudah penghapusan. File ini menunjukkan cara penggunaan semua fungsi yang telah dideklarasikan di Doublylist.h dan diimplementasikan di Doublylist.cpp.


## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file "Doublylist.h":
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Unguided1/Soal1.png)

### Buatlah implementasi ADT Doubly Linked list pada file "Doublylist.cpp" dan coba hasil implementasi ADT pada file "main.cpp".

![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Unguided1/Soal2.png)

1. **Data Doublylist1.h** 

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

// ====== TYPE DEFINITION ======
struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== PROTOTYPE UNTUK SOAL 1 ======
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);


#endif 
```

2. **Data Doublyslist1.cpp** 

```C++
#include "Doublylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1\n";
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

```


3. **Data Main.cpp** 

```C++
#include "Doublylist.h"

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

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Output/Jawabanno1.png)

Program ini digunakan untuk mengelola data kendaraan menggunakan struktur Doubly Linked List dalam bahasa C++. Setiap node menyimpan informasi berupa nomor polisi, warna, dan tahun pembuatan kendaraan, serta memiliki dua penunjuk (next dan prev) agar data dapat diakses dua arah. Program diawali dengan pembuatan list kosong, kemudian pengguna memasukkan beberapa data kendaraan yang disimpan ke dalam list melalui proses alokasi dan penyisipan di bagian akhir menggunakan fungsi insertLast. Setelah data dimasukkan, program menampilkan seluruh isi list dengan fungsi printInfo. Dengan pemisahan file header, implementasi, dan main, program ini menunjukkan penerapan konsep modularisasi dan struktur data dinamis yang memungkinkan pengelolaan data secara efisien serta fleksibel.
### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Unguided2/Soal2.png)


1. **Data Doublylist2.h** 

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

// ====== PROTOTYPE UNTUK SOAL 1 ======
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);

#endif

```

2. **Data Doublyslist2.cpp** 

```C++
#include "Doublylist2.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1\n";
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

```


3. **Data Main.cpp** 

```C++
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


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Output/Jawabanno2.png)

Program ini digunakan untuk menyimpan, menampilkan, dan mencari data kendaraan menggunakan struktur Doubly Linked List di C++. Setiap data kendaraan berisi nomor polisi, warna, dan tahun pembuatan yang disimpan dalam node (ElmList) dengan dua arah hubungan, yaitu next dan prev. Program dimulai dengan membuat list kosong menggunakan fungsi createList, kemudian pengguna dapat memasukkan beberapa data kendaraan yang disimpan ke dalam list melalui fungsi insertLast. Selanjutnya, seluruh data kendaraan ditampilkan menggunakan fungsi printInfo. Program juga memiliki fitur pencarian data berdasarkan nomor polisi dengan fungsi findElm, yang menelusuri setiap elemen hingga menemukan data yang dicari atau menampilkan pesan jika data tidak ditemukan. Dengan penerapan Doubly Linked List, program dapat menambah dan menelusuri data secara efisien dari kedua arah, serta menjaga struktur data tetap terorganisir dan mudah dikelola.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete.
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Unguided3/Soal3.png)


1. **Data Doublylist3.h** 

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;


struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};


void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P, List &L);


#endif
```

2. **Data Doublylist3.cpp** 

```C++
#include "Doublylist3.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1\n";
    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = L.First->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = L.Last->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void deleteAfter(address Prec, address &P, List &L) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        } else {
            L.Last = Prec; 
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}


```


3. **Data Main.cpp** 

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan6_Modul6/Output/Jawabanno3.png)

Program ini digunakan untuk menyimpan, menampilkan, mencari, dan menghapus data kendaraan menggunakan struktur Doubly Linked List di C++. Setiap node menyimpan data kendaraan berupa nomor polisi, warna, dan tahun pembuatan, serta memiliki dua pointer (next dan prev) untuk menghubungkan elemen secara dua arah. Fungsi createList digunakan untuk membuat list kosong, insertLast untuk menambahkan data di akhir list, dan printInfo untuk menampilkan seluruh isi list. Program juga menyediakan fungsi findElm untuk mencari data berdasarkan nomor polisi, serta tiga operasi penghapusan: deleteFirst untuk menghapus elemen pertama, deleteLast untuk elemen terakhir, dan deleteAfter untuk elemen di tengah. Proses di main program dimulai dengan input data kendaraan, kemudian pengguna dapat menghapus data tertentu berdasarkan nomor polisi. Program ini memperlihatkan penerapan konsep manajemen data dinamis dengan Doubly Linked List yang memungkinkan operasi penambahan, pencarian, dan penghapusan dilakukan secara efisien di kedua arah.

## Kesimpulan
Kesimpulannya, ketiga program Doublylist1, Doublylist2, dan Doublylist3 menggambarkan proses bertahap dalam memahami dan mengimplementasikan struktur data Doubly Linked List menggunakan bahasa C++. Pada program Doublylist1, fokus utama adalah pembuatan struktur dasar list ganda, yang terdiri dari node dengan pointer next dan prev, serta fungsi dasar seperti createList, alokasi, insertLast, dan printInfo. Program ini menunjukkan bagaimana elemen-elemen baru dapat ditambahkan ke akhir list dan kemudian ditampilkan dalam urutan yang benar. Pada tahap berikutnya, Doublylist2 memperluas kemampuan tersebut dengan menambahkan fungsi pencarian data (findElm) berdasarkan nomor polisi, sehingga pengguna dapat mencari elemen tertentu dalam list. Hal ini menunjukkan kemampuan traversal dua arah pada Doubly Linked List yang memudahkan dalam menelusuri dan mengakses data tertentu. Terakhir, Doublylist3 melengkapi fitur-fitur sebelumnya dengan kemampuan menghapus elemen list dari posisi mana pun — baik di awal (deleteFirst), di akhir (deleteLast), maupun di tengah (deleteAfter). Dengan demikian, program ini sudah mencakup seluruh operasi dasar yang dibutuhkan dalam manipulasi data list ganda, yaitu membuat, menambah, menelusuri, mencari, dan menghapus data. Secara keseluruhan, ketiga program ini memberikan pemahaman yang mendalam tentang bagaimana Doubly Linked List bekerja secara dinamis, di mana setiap elemen saling terhubung dua arah sehingga memungkinkan operasi penambahan dan penghapusan dilakukan dengan efisien tanpa harus memindahkan seluruh data seperti pada array. Melalui pendekatan modular dengan file header (.h), implementasi (.cpp), dan main program (main.cpp), ketiga versi ini juga menekankan pentingnya struktur kode yang terorganisasi dan mudah dikembangkan. Dari tahap dasar hingga kompleks, rangkaian program Doublylist ini menunjukkan bagaimana konsep teori struktur data diterapkan dalam praktik pemrograman nyata untuk mengelola kumpulan data yang bersifat dinamis dan fleksibel.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1290-1293. Diperoleh dari: https://jurnalmahasiswa.com/index.php/jriin/article/view/957
    