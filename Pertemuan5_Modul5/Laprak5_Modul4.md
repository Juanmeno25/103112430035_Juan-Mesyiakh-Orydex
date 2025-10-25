# <h1 align="center">Laporan Praktikum Modul 4 - Singly Link List Bagian 2 Searching (Binnary Shearching & Linear Searching)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori
Linked List adalah struktur data yang terdiri dari serangkaian node, di mana setiap node berisi elemen data dan sebuah pointer yang menunjuk ke node berikutnya. Terdapat beberapa jenis linked list, termasuk singly linked list,doubly linked list, dan circular linked list.Linked  List  lebih  fleksibel  dibandingkan  array  dalam  hal  penambahan  dan  penghapusan elemen, karena tidak memerlukan pergeseran elemen-elemen lain.


   **SINGLY LINKED LIST**  
   Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string. Linked list dapat diimplementasikan menggunakan Array dan Pointer (Linked list).

   **SEARCHING**  
    Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan update akan lebih mudah.



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
Menurut (Joko Musridho, 2024) (Ahmad, 2024)Single Linked list adalah daftar terhubung yang setiap simpul pembentuknya mempunyai satu rantai(link) ke simpul lainnya. Simpul yang saling terhubung satu sama lain dengan menggunakan pointer. Setiap simpul dalam singly Linked list memiliki dua bagian, yaitu data dan pointer yang menunjuk ke simpul berikutnya. Singly Linked list hanya memiliki satu arah, yaitu dari simpul awal (head) ke simpul akhir (tail).


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
### D. Searching
 Search adalah kegiatan mencari data, baik untuk memastikan keberadaan maupun mengetahui posisi data. Algoritma search penting dalam sistem komputer, seperti search engine, basis data, dan pencarian file, karena membuat proses lebih cepat dan efisien. Beberapa algoritma search yang umum digunakan antara lain
 ##### 1. Sequential Search: memeriksa data satu per satu sesuai urutan hingga ditemukan.
 ##### 2. Binary Search: membagi data menjadi dua bagian untuk mencari elemen dengan lebih cepat.
 Algoritma search membantu meningkatkan efisiensi pencarian, terutama pada data besar dan kompleks.

1. **Binnary Search**

 ```cpp
Node *binarySearch(Node* head, int key) {
   int size = 0;
   for(Node*current = head; current; current = current->next) size++;
Node* start = head;
Node* end = nullptr;
while(size > 0) {
    int mid = size / 2;
    Node* midNode = start;
    for(int i = 0; i < mid; i++) midNode = midNode->next;

    if(midNode->data == key) return midNode;
    if(midNode->data < key) {
        start = midNode->next;
    } else {
        end = midNode;
    } 
    size = mid;
    }
    return nullptr;
}

   ```

2. **Linear Search**

 ```cpp
Node*linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

   ```

---

## Guided 

### 1. List Buah
1. **Data listBuah.h** 

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama; 
    int jumlah;
    float harga;
};

typedef buah dataBuah;

typedef struct node *address;

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);

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

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
File LISTBUAH_H hanya berisi struktur data dan deklarasi fungsi untuk linked list buah. Di sini ada tipe data buah, node, dan linkedlist, serta fungsi-fungsi untuk membuat list, menambah, menghapus, menampilkan, menghitung, dan memperbarui data. File ini hanya memberitahu apa yang tersedia, sedangkan cara kerjanya ada di file .cpp terpisah.

2. **Data listBuah.cpp** 

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

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

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
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
    if (Prev != Nil) {
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
        cout << "Node pertama berhasil terhapus!" << endl;
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
        cout << "Node terakhir berhasil terhapus!" << endl;
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
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
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
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
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
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
File ini mengimplementasikan semua fungsi yang dideklarasikan di listBuah.h untuk mengelola linked list buah. Ada fungsi untuk mengecek list kosong, membuat list baru, membuat node baru (alokasi), dan menghapus node (dealokasi). Selain itu, ada prosedur untuk menambahkan node (insertFirst, insertAfter, insertLast), menghapus node (delFirst, delAfter, delLast), menampilkan isi list (printList), menghitung jumlah node (nbList), dan menghapus seluruh list (deleteList).

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
### 2. Binnary Search

```C++
#include <iostream>
using namespace std;

struct  Node{
    int data;
    Node*next;
};

void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node *binarySearch(Node* head, int key) {
   int size = 0;
   for(Node*current = head; current; current = current->next) size++;
Node* start = head;
Node* end = nullptr;
while(size > 0) {
    int mid = size / 2;
    Node* midNode = start;
    for(int i = 0; i < mid; i++) midNode = midNode->next;

    if(midNode->data == key) return midNode;
    if(midNode->data < key) {
        start = midNode->next;
    } else {
        end = midNode;
    } 
    size = mid;
    }
    return nullptr;
}
int main(){
    Node*head = nullptr;
    append(head,10);
    append(head,20); 
    append(head,30);
    append(head,40);
    append(head,50);

    Node*result = binarySearch(head,40);
    cout << (result ? "Found" : "Not Found") << endl;
    return 0;
}

#endif
```
Program ini membuat singly linked list yang menyimpan data integer dan menyediakan fungsi untuk menambahkan node (append) di akhir list. Selain itu, ada fungsi binarySearch untuk mencari sebuah nilai dalam linked list menggunakan konsep binary search dengan menghitung ukuran list, mencari node tengah, dan memotong pencarian berdasarkan nilai node tengah. Di main, program membuat linked list dengan nilai 10, 20, 30, 40, 50, lalu mencari nilai 40 menggunakan binarySearch dan menampilkan "Found" jika ditemukan atau "Not Found" jika tidak.

### 3. Linear Search

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node*linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}
void append(Node* &head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}
int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    Node* result = linearSearch(head, 30);

    cout << (result ? "Found" : "Not Found") << endl;
    return 0;  
}

#endif
```
Program ini membuat singly linked list yang menyimpan data integer, dengan fungsi append untuk menambahkan node di akhir list. Fungsi linearSearch digunakan untuk mencari sebuah nilai dengan menelusuri node satu per satu hingga ditemukan atau sampai akhir list. Di main, program membuat linked list dengan nilai 10, 20, dan 30, lalu mencari nilai 30 menggunakan linearSearch dan menampilkan "Found" jika nilai ditemukan atau "Not Found" jika tidak.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
#### 1. Membuat linked list dengan menambahkan node di akhir
#### 2. Mengimplementasikan binary search pada linked list
#### 3. Menampilkan detail proses pencarian dan hasil akhir
### Petunjuk Tugas 1:
#### 1. Gunakan struktur Node dengan data integer dan pointer next 
#### 2. Implementasikan fungsi append() untuk menambah node
#### 3. Implementasikan fungsi binarySearch () yang mengembalikan pointer ke node yang ditemukan 
#### 4. Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
#### 5. Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
#### 6. Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian
### Ekspetasi Output:
### Jangan berekspetasi sama manusia, takutnya dikecewakan. Berekspetasilah pada diri sendiri yang mau berjuang.

![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan5_Modul5/Unguided1/Soal1.png)


```C++
#include <iostream>
using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi menambah node di akhir
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Menampilkan isi linked list
void display(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Mendapatkan node tengah (antara start dan end)
Node* getMiddle(Node* start, Node* end, int& index) {
    if (!start) return nullptr;
    Node* slow = start;
    Node* fast = start->next;
    index = 0;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
            index++;
        }
    }
    return slow;
}

// Binary Search di linked list
Node* binarySearch(Node* head, int target) {
    Node* start = head;
    Node* end = nullptr;
    int iter = 1;

    cout << "\nProses Pencarian:\n";
    while (start != end) {
        int index = 0;
        Node* mid = getMiddle(start, end, index);
        if (!mid) break;

        cout << "Iterasi " << iter++ << ": Mid = " << mid->data 
             << " (indeks tengah)";

        if (mid->data == target) {
            cout << " - DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << target << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << mid << endl;
            cout << "Data node: " << mid->data << endl;
            if (mid->next)
                cout << "Node berikutnya: " << mid->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return mid;
        } 
        else if (mid->data < target) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next;
        } 
        else {
            cout << " -> Cari di bagian kiri\n";
            end = mid;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << target << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST\n";

    // Membuat linked list 
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    display(head);

    // Tes 1
    int target = 40;
    cout << "Mencari nilai: " << target << endl;
    binarySearch(head, target);

    // Tes 2
    target = 25;
    cout << "\nMencari nilai: " << target << endl;
    binarySearch(head, target);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan5_Modul5/Output/Jawabanno1.png)

Program ini digunakan untuk menyimpan, menampilkan, dan mencari data angka dalam struktur Singly Linked List menggunakan konsep modularisasi fungsi di C++. Struktur data Node menyimpan satu elemen data bertipe int dan penunjuk ke elemen berikutnya. Program ini memiliki beberapa fungsi utama, yaitu append untuk menambahkan node baru di akhir linked list, display untuk menampilkan seluruh isi linked list dari node pertama hingga node terakhir, getMiddle untuk menemukan node tengah antara node awal dan akhir yang digunakan dalam proses binary search, serta binarySearch untuk melakukan pencarian nilai tertentu dalam linked list. Fungsi binary search ini menampilkan setiap iterasi pencarian, nilai node tengah yang diperiksa, arah pencarian (kiri atau kanan), dan hasil apakah nilai ditemukan atau tidak. Pada bagian utama program, linked list pertama-tama dibuat kosong, kemudian beberapa data seperti 10, 20, 30, 40, 50, dan 60 ditambahkan ke dalam linked list menggunakan fungsi append. Selanjutnya, seluruh isi linked list ditampilkan dengan menggunakan fungsi display. Program kemudian melakukan pencarian terhadap beberapa nilai menggunakan fungsi binarySearch, menampilkan proses pencarian beserta hasilnya. Program ini menunjukkan cara pembuatan, penambahan, penampilan, dan pencarian data pada linked list. Meskipun binary search biasanya lebih cocok digunakan pada array, program ini memodifikasi konsep binary search agar bisa diterapkan pada linked list dengan traversal node demi node. Dengan penerapan modularisasi fungsi, kode menjadi lebih rapi dan setiap tugas seperti penambahan, tampilan, dan pencarian dipisahkan ke dalam fungsi masing-masing, sehingga memudahkan pemahaman dan pemeliharaan program.
### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
####   1. Membuat linked list dengan menambahkan node di akhir
####   2. Mengimplementasikan linear search pada linked list
####   3. Menampilkan detail proses pencarian dan hasil akhir 
### Petunjuk Tugas 2:
####   1. Gunakan struktur Node dengan data integer dan pointer next
####   2. Implementasikan fungsi append() untuk menambah node
####   3. Implementasikan fungsi linearSearch () yang mengembalikan pointer ke node yang ditemukan
####   4. Data dalam linked list tidak perlu terurut untuk linear search
####   5. Tampilkan setiap langkah pencarian dan node yang sedang diperiksa
####   6. Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian
### Ekspetasi Output:
#### Dulu pernah berekspetasi pada seseorang, tapi hasilnya dikecewakan. Jadinya hanya bisa berekspetasi atas kerja keras diri sendiri.
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan5_Modul5/Unguided2/Soal2.png)


```C++
#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* next;
};

// Tambahkan node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Tampilkan isi linked list
void display(Node* head) {
    cout << "Linked List yang dibuat: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Linear Search
Node* linearSearch(Node* head, int target) {
    Node* temp = head;
    int index = 1;

    cout << "\nProses Pencarian:\n";

    while (temp) {
        cout << "Memeriksa node " << index << ": " << temp->data << " ";
        if (temp->data == target) {
            cout << "(SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << target << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node: " << temp << endl;
            cout << "Data node: " << temp->data << endl;
            if (temp->next)
                cout << "Node berikutnya: " << temp->next->data << endl;
            else
                cout << "Node berikutnya: NULL\n";
            return temp;
        } else {
            cout << "(tidak sama)" << endl;
        }
        temp = temp->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    cout << "\nHasil: Nilai " << target << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    // Membuat linked list (data terurut)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    display(head);

    // Pencarian pertama
    int target = 30;
    cout << "Mencari nilai: " << target << endl;
    linearSearch(head, target);

    // Pencarian kedua
    target = 25;
    cout << "\nMencari nilai: " << target << endl;
    linearSearch(head, target);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan5_Modul5/Output/Jawabanno2.png)

Program ini digunakan untuk menyimpan, menampilkan, dan mencari data angka dalam struktur Singly Linked List menggunakan metode linear search. Struktur data Node menyimpan satu elemen data bertipe int dan penunjuk ke elemen berikutnya. Program memiliki beberapa fungsi utama, yaitu append untuk menambahkan node baru di akhir linked list, display untuk menampilkan seluruh isi linked list dari node pertama hingga node terakhir, dan linearSearch untuk mencari nilai tertentu dengan cara memeriksa setiap node satu per satu hingga nilai yang dicari ditemukan atau semua node telah diperiksa. Pada bagian utama program, linked list pertama-tama dibuat kosong, kemudian beberapa data seperti 10, 20, 30, 40, dan 50 ditambahkan ke dalam linked list menggunakan fungsi append. Selanjutnya, seluruh isi linked list ditampilkan menggunakan fungsi display. Program kemudian melakukan pencarian terhadap beberapa nilai menggunakan fungsi linearSearch, menampilkan proses pemeriksaan setiap node, hasil apakah nilai ditemukan, alamat node yang berisi nilai tersebut, data node, serta informasi node berikutnya jika ada. Program ini menunjukkan cara pembuatan, penambahan, penampilan, dan pencarian data dalam linked list menggunakan metode linear search. Dengan penerapan modularisasi fungsi, kode menjadi lebih rapi dan mudah dipahami, serta setiap tugas seperti penambahan, tampilan, dan pencarian dipisahkan ke dalam fungsi masing-masing.
## Kesimpulan
Berdasarkan program yang telah dibuat, linear search pada linked list memeriksa setiap node satu per satu dari awal hingga akhir untuk mencari nilai tertentu. Metode ini sederhana dan mudah diterapkan pada linked list karena setiap node hanya terhubung ke node berikutnya. Namun, proses pencarian bisa memakan waktu lebih lama jika jumlah node banyak, seperti terlihat pada saat mencari nilai 25 yang tidak ada dalam linked list. Sementara itu, binary search yang diterapkan pada linked list memanfaatkan konsep pencarian pada data terurut dengan mencari node tengah dan mempersempit pencarian ke bagian kiri atau kanan. Proses ini terlihat pada saat mencari nilai 40, di mana program menampilkan iterasi dan node tengah setiap langkah pencarian. Binary search lebih efisien dibanding linear search jika data sudah terurut, tetapi penerapannya pada linked list lebih rumit karena membutuhkan traversal untuk menemukan node tengah.Secara keseluruhan, linear search lebih sederhana dan fleksibel untuk linked list, sedangkan binary search lebih cepat pada data terurut, namun kompleksitas implementasinya lebih tinggi dibanding linear search pada linked list.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1290-1293. Diperoleh dari: https://jurnalmahasiswa.com/index.php/jriin/article/view/957
<br>[3]Setiyawan, R. D., Hermawan, D., Abdillah, A. F., & Mujayanah, A. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2). Diperoleh dari: https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263
<br>[4] Alfina, S. T., Adi Ahmad, S. K., Yeni Yanti, S. T., & Munawir, S. T. (2024). Algoritma dan Pemrograman. CV. Naskah Aceh. ISBN 978-623-88939-6-6. Diperoleh dari: https://www.researchgate.net/publication/382560738_ALGORITMA_DAN_PEMROGRAMAN
<br>[5] Musridho, R. Joko. (2024). Diktat STRUKTUR DATA. Diperoleh dari: https://repository.universitaspahlawan.ac.id/1887/1/%282024%29%20Musridho%20-%20Diktat%20Struktur%20Data.pdf
<br>[6] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., & Mujayanah, A. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2). Diperoleh dari: https://www.jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263/pdf
<br>[7] Toyib, R., Darnita, Y., & Deva, A. R. S. (2021). Penerapan algoritma binary search pada aplikasi e-order. Jurnal Media Infotama, 17(1). https://jurnal.unived.ac.id/index.php/jmi/article/view/1314/1074
<br>[8] Wijaya, A., Maulana, M. F., & Danil, M. (2021). Aplikasi pencarian resep masakan khas Bengkulu menggunakan algoritma binary search berbasis Android. Jurnal Sistem Komputer, 5(2). https://e-jurnal.stmikbinsa.ac.id/index.php/simkom/article/view/857/131
<br>[9] GeeksforGeeks. (2025, 2 Juli). Linear Search vs Binary Search. https://www.geeksforgeeks.org/dsa/linear-search-vs-binary-search/?utm_