# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori
Linked List adalah struktur data yang terdiri dari serangkaian node, di mana setiap node berisi elemen data dan sebuah pointer yang menunjuk ke node berikutnya. Terdapat beberapa jenis linked list, termasuk singly linked list,doubly linked list, dan circular linked list.Linked  List  lebih  fleksibel  dibandingkan  array  dalam  hal  penambahan  dan  penghapusan elemen, karena tidak memerlukan pergeseran elemen-elemen lain.


   **SINGLY LINKED LIST**  
   Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string. Linked list dapat diimplementasikan menggunakan Array dan Pointer (Linked list).
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
### C. Singly Linked List
Singly Linked list Menurut (Joko Musridho, 2024) (Ahmad, 2024)Single Linked list adalah
Daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. Simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly Linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly Linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail).


   ```cpp

/*file list.h*/
#ifndef LIST H INCLUDED #define LIST_H_INCLUDED
#define Nil NULL
using namespace std;
/*deklarasi record dan struktur data list*/
typedef int infotype;
typdef struct elmlist *address;
struct elmlist {
infotype info;
address next;
};
struct list{
address first;
};
#endif // TEST_H_INCLUDED

   ```
---

## Guided 

### 1. Singly Linked List
1. **Data list.h** 

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
File .h ini hanya berisi struktur data dan deklarasi fungsi, tanpa menjelaskan cara kerja detailnya. Artinya, file lain seperti main.cpp hanya tahu bahwa ada tipe data mahasiswa, node, dan linkedlist, serta fungsi-fungsi seperti createList, insertFirst, dan printList, tapi tidak tahu bagaimana fungsi-fungsi itu diimplementasikan.

2. **Data list.cpp** 

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
File .cpp ini berisi cara kerja atau implementasi detail dari fungsi-fungsi yang ada di list.h. Misalnya bagaimana cara membuat list kosong, menambah data di awal/tengah/akhir list, menghapus node, dan menampilkan isi list. Jadi, kalau list.h hanya mendefinisikan apa saja fungsi yang tersedia, file .cpp ini menjelaskan bagaimana fungsi-fungsi itu dijalankan secara lengkap.

3. **Data Main.cpp** 

```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
File ini berfungsi untuk menjalankan program utama yang memanfaatkan semua operasi dari ADT Linked List. Di sini dibuat beberapa node mahasiswa (Dhimas, Arvin, Rizal, dll.), lalu dilakukan operasi insert di berbagai posisi (awal, tengah, akhir). Setelah itu, isi Linked List ditampilkan ke layar dengan printList(List). Jadi, kalau list.h mendefinisikan strukturnya, list.cpp menjelaskan cara kerjanya, maka main.cpp ini menunjukkan cara menggunakan linked list tersebut dalam program.

### 2. Singly Linked List Delete
1. **Data list.h** 

```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```
File .h ini hanya berisi struktur data dan deklarasi fungsi, tanpa menjelaskan cara kerja detailnya. Artinya, file lain seperti main.cpp hanya tahu bahwa ada tipe data mahasiswa, node, dan linkedlist, serta fungsi-fungsi seperti createList, insertFirst, dan printList, tapi tidak tahu bagaimana fungsi-fungsi itu diimplementasikan.

2. **Data list.cpp** 

```C++
// list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

```
File list.cpp ini berisi implementasi detail dari setiap fungsi yang ada di list.h. Di sini dijelaskan bagaimana cara kerja operasi pada Linked List, seperti membuat list kosong (createList), menambah node (insertFirst, insertLast, insertAfter), menghapus node (delFirst, delLast, delAfter), menampilkan isi list (printList), menghitung jumlah elemen (nbList), dan menghapus seluruh list (deleteList).

3. **Data Main.cpp** 

```C++


// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
File main.cpp berfungsi sebagai program utama untuk menguji seluruh operasi pada Linked List. Di dalamnya dibuat beberapa data mahasiswa (Dhimas, Arvin, Rizal, Satrio, Joshua) menggunakan fungsi alokasi, lalu dilakukan operasi insert di berbagai posisi (awal, tengah, dan akhir). Setelah itu, program menampilkan isi list dan jumlah node menggunakan printList dan nbList. Program juga menguji fungsi penghapusan (delFirst, delLast, delAfter) serta menghapus seluruh list dengan deleteList.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h"
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Soal/soal1.png)
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file "Singlylist.cpp" Kemudian buat program utama didalam file "main.cpp" dengan implementasi sebagai berikut :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Soal/soal12.png)
### Sehingga linkedlist yang dibuat akan seperti ini :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Soal/soal123.png)
### Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Soal/soal1234.png)
1. **Data Singlylist.h** 

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif

```

2. **Data Singlylist.cpp** 

```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```


3. **Data main.cpp** 

```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L); // Output: 9 12 8 0 2
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Output/jawaban1.png)

Program ini digunakan untuk menyimpan dan menampilkan data angka menggunakan konsep modularisasi dengan pemisahan file header (.h) dan file implementasi (.cpp). Struktur data ElmList digunakan untuk menyimpan satu elemen data bertipe int (info) dan penunjuk ke elemen berikutnya (next). Struktur List berfungsi sebagai penampung utama yang menyimpan alamat elemen pertama dalam linked list. Fungsi createList digunakan untuk membuat list kosong, sedangkan alokasi membuat node baru berisi data yang diinputkan. Fungsi insertFirst menambahkan node baru di bagian awal list, dan printInfo digunakan untuk menampilkan semua data yang tersimpan di list. Pada bagian main, program membuat list baru, kemudian menambahkan beberapa data (9, 12, 8, 0, dan 2) ke dalamnya menggunakan fungsi insertFirst. Terakhir, fungsi printInfo menampilkan seluruh isi list di layar. Program ini menunjukkan cara pembuatan, penambahan, dan penampilan data dalam struktur Singly Linked List dengan penerapan modularisasi program menggunakan file header dan file implementasi di C++.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). Output yang diharapkan :
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Soal/soal2.png)
1. **Data Singlylist.h** 

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address P);
void insertFirst(List &L, address P);
void printInfo(List L);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif

```

2. **Data Singlylist.cpp** 

```C++
#include "Singlylist.h"

void createList(List &L) { L.first = Nil; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address P) { delete P; }

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address Q = L.first;
        if (Q->next == Nil) {
            P = Q;
            L.first = Nil;
        } else {
            while (Q->next->next != Nil)
                Q = Q->next;
            P = Q->next;
            Q->next = Nil;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int n = 0;
    for (address P = L.first; P != Nil; P = P->next) n++;
    return n;
}

void deleteList(List &L) {
    address P;
    while (L.first != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
```
3. **Data main.cpp** 

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan4_Modul4/Output/jawaban2.png)

Program ini digunakan untuk menyimpan, menampilkan, dan menghapus data angka menggunakan konsep modularisasi dengan pemisahan file menjadi file header (.h), file implementasi (.cpp), dan file utama (main.cpp). Struktur data ElmList digunakan untuk menyimpan satu elemen data bertipe int (info) serta penunjuk ke elemen berikutnya (next). Struktur List berfungsi sebagai penampung utama yang menyimpan alamat elemen pertama dalam singly linked list. Pada bagian main, program membuat list baru, kemudian menambahkan beberapa data (9, 12, 8, 0, dan 2) menggunakan fungsi insertFirst sehingga membentuk urutan 9 12 8 0 2. Setelah itu dilakukan beberapa operasi penghapusan node, penampilan jumlah node, dan penghapusan seluruh elemen list. Secara keseluruhan, program ini menunjukkan cara pembuatan, penambahan, penghapusan, dan penampilan data pada struktur Singly Linked List dengan penerapan modularisasi program menggunakan file header dan file implementasi di bahasa C++.
## Kesimpulan
Pada program pertama (Singly Linked List versi dasar), ADT digunakan untuk merepresentasikan struktur data daftar berantai yang berisi elemen-elemen bertipe integer dengan operasi dasar seperti menambah dan menampilkan data. Program kedua memperluas konsep ini dengan menambahkan operasi penghapusan elemen (deleteFirst, deleteLast, dan deleteAfter) serta perhitungan jumlah elemen dalam list, yang menunjukkan kemampuan ADT dalam mengelola data secara dinamis menggunakan pointer. Pemisahan file header, implementasi, dan main program juga menegaskan prinsip modularisasi, di mana pengguna hanya perlu mengetahui fungsi-fungsi yang tersedia tanpa memahami detail implementasinya. Secara keseluruhan, program ini memperlihatkan bahwa penerapan Abstract Data Type (ADT) dalam C++ memungkinkan pengembang untuk membangun struktur data yang terorganisir, fleksibel, dan efisien, sekaligus memisahkan logika internal dari penggunaannya untuk meningkatkan keterbacaan dan pemeliharaan kode.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1290-1293. Diperoleh dari: https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3]Setiyawan, R. D., Hermawan, D., Abdillah, A. F., & Mujayanah, A. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2). Diperoleh dari: https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[4] Alfina, S. T., Adi Ahmad, S. K., Yeni Yanti, S. T., & Munawir, S. T. (2024). Algoritma dan Pemrograman. CV. Naskah Aceh. ISBN 978-623-88939-6-6. Diperoleh dari: https://www.researchgate.net/publication/382560738_ALGORITMA_DAN_PEMROGRAMAN
<br>[5] Musridho, R. Joko. (2024). Diktat STRUKTUR DATA. Diperoleh dari: https://repository.universitaspahlawan.ac.id/1887/1/%282024%29%20Musridho%20-%20Diktat%20Struktur%20Data.pdf
<br>[6] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., & Mujayanah, A. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2). Diperoleh dari: https://www.jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263/pdf