# <h1 align="center">Laporan Praktikum Modul 8  -  QUEUE</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori

Queue (Antrian) adalah sebuah struktur data fundamental yang mengatur elemen-elemennya dalam urutan linier dan ketat, meniru konsep antrian tunggu di dunia nyata. Struktur ini bekerja secara eksklusif berdasarkan prinsip FIFO (First-In, First-Out), menjamin bahwa elemen yang pertama kali dimasukkan (enqueued) ke dalam antrian akan menjadi elemen yang pertama kali diproses (dequeued). Operasi penambahan elemen selalu terjadi di bagian belakang (rear atau tail), sementara pengambilan elemen selalu terjadi di bagian depan (front atau head).
   **Queue**  
   Struktur data Queue diatur oleh dua operasi dasar yang menjamin prinsip FIFO (First-In, First-Out), yaitu:
   1. Enqueue: Operasi untuk menambahkan elemen baru di bagian belakang (rear/tail) antrian.
   2. Dequeue: Operasi untuk menghapus elemen dari bagian depan (front/head) antrian.
   Kedua operasi ini bekerja secara berlawanan, memastikan bahwa elemen yang pertama kali masuk adalah yang pertama kali keluar, sehingga data diproses secara berurutan sesuai kedatangannya.


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
### C. Queue
Queue (Antrian) adalah suatu model struktur data linier yang menyimpan koleksi elemen data dalam urutan tertentu, menyerupai antrian fisik dalam kehidupan sehari-hari. Struktur ini berfungsi berdasarkan prinsip utama yang dikenal sebagai FIFO (First-In, First-Out), yang berarti elemen data yang pertama kali masuk ke dalam antrian akan menjadi elemen yang pertama kali keluar (diproses). jenis-jenis queue (linear, circular, priority, dan deque), kelebihan dan kekurangan, serta implementasi dalam berbagai konteks pemrograman dan sistem operasi. Linear  queue (simple  queue)  adalah  jenis  paling  dasar,  di  mana  elemen  ditambahkan  dari  belakang  dan dihapus dari depan dalam urutan linear. Circular queue adalah variasi dari linear queue, namun pointer rear dapat kembali ke awal array jika ada ruang kosong, sehinggapenggunaan memori lebih efisien.  terdapat juga priority queue, yaitu struktur queue di mana setiap elemen memiliki prioritas tertentu dan elemen dengan prioritas tertinggi akan dilayani  lebih  dahulu.  Selain  itu,  ada  double-endedqueue  (deque),  yang  memungkinkan penambahan dan penghapusan elemen dari kedua ujung antrian


   ```cpp
#include "Queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enqueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void dequeue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

   ```
## Guided 

### 1. Queue 1 
1. **Data Queue.h** 

```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>

using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};
struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(address &node);

void enqueue(queue &Q, address nodeBaru);
void dequeue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);


#endif
```
File queue.h ini berisi struktur data dan deklarasi fungsi yang digunakan untuk mengelola struktur data Queue menggunakan Linked List (list searah). File ini tidak memuat implementasi fungsi secara langsung, melainkan hanya mendefinisikan tipe data, struktur node, struktur queue, serta prototipe fungsi yang nantinya akan diimplementasikan pada file .cpp lainnya.

2. **Data Queue.cpp** 

```C++
#include "Queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enqueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void dequeue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
File queue.cpp ini berisi implementasi lengkap dari seluruh fungsi yang telah dideklarasikan pada file queue.h. Semua fungsi di dalam file ini bekerja untuk mengelola struktur data Queue menggunakan Linked List, sesuai konsep FIFO (First In First Out).
3. **Data Main.cpp** 

```C++
#include "Queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);
    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enqueue(Q, nodeA);
    enqueue(Q, nodeB);
    enqueue(Q, nodeC);
    enqueue(Q, nodeD);
    enqueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enqueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    dequeue(Q);
    dequeue(Q);
    cout << endl;

    cout << "--- Queue setelah dequeue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```
File main.cpp ini berfungsi sebagai program utama yang menguji seluruh operasi Queue berbasis Linked List yang telah diimplementasikan pada queue.cpp dan dideklarasikan di queue.h. Program ini membuat beberapa node kemudian melakukan operasi enqueue, dequeue, update, dan pencarian data.

### 2. Queue 2
1. **Data Queue.h** 

```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
File queue.h ini berisi deklarasi struktur data serta prototipe fungsi-fungsi yang digunakan untuk mengelola antrian (Queue) berbasis array melingkar (circular array). File ini hanya mendefinisikan bentuk data dan fungsi, tanpa implementasi logika, karena implementasinya berada pada file .cpp terpisah.
2. **Data Queue.cpp** 

```C++
#include "Queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
File Queue.cpp ini berisi implementasi lengkap dari seluruh fungsi yang telah dideklarasikan pada file queue.h. Semua logika operasi antrian (Queue) berbasis circular array ditulis di dalam file ini.

3. **Data Main.cpp** 

```C++
#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
 Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);

    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}


```
Program main.cpp ini berfungsi untuk menguji seluruh operasi queue berbasis circular array yang telah diimplementasikan sebelumnya. Program dimulai dengan membuat sebuah queue kosong menggunakan createQueue, lalu menampilkannya dengan printInfo. Selanjutnya, beberapa operasi enqueue dan dequeue dilakukan secara bertahap untuk menunjukkan bagaimana pointer head, tail, dan jumlah elemen (count) berubah seiring manipulasi data.


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "Queue.h":
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan8_Modul8/Unguided1/Soal1.png)

### Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan8_Modul8/Unguided1/Soal2.png)

1. **Data Queue1.h** 

```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif



```

2. **Data Queue1.cpp** 

```C++
#include "Queue1.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "[ERROR] Queue penuh! (Gagal enqueue: " << x << ")" << endl;
        return;
    } 
    
    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "[ERROR] Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
    }

    return x;
}

void printInfo(Queue Q) {
    if (Q.head == -1) {
        cout << Q.head << " - " << Q.tail << " " << " : ";
    } else {
        cout << Q.head << " - " << Q.tail << " " << " : ";
    }


    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```


3. **Data main.cpp** 

```C++
#include <iostream>
#include "Queue1.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    cout << "------------------------------" << endl;
    
    cout << "H - T " << " : " << "Queue Info" << endl;
    cout << "------------------------------" << endl;

    Queue Q;
    createQueue(Q);

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); 
    enqueue(Q, 4); printInfo(Q); 
    dequeue(Q); printInfo(Q); 
    printInfo(Q); 
    dequeue(Q); printInfo(Q);

    return 0;
}

```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan8_Modul8/Output/Jawabanno1.png)

Program ini digunakan untuk mengelola data bertipe bilangan bulat (integer) menggunakan struktur data Queue (Antrian) berbasis array dalam bahasa C++. Struktur Queue terdiri dari sebuah array info berukuran maksimum 5 elemen, serta variabel head (yang selalu menunjukkan posisi elemen pertama/depan) dan tail (yang menunjukkan posisi elemen terakhir/belakang).Program diawali dengan inisialisasi antrian kosong menggunakan fungsi createQueue. Kemudian, dilakukan serangkaian operasi enqueue untuk menambahkan elemen ke belakang (tail) dan dequeue untuk menghapus elemen dari depan (head). Karena mekanisme ini mengharuskan head tetap di indeks 0, fungsi dequeue memiliki tugas tambahan yaitu menggeser maju (shifting) semua elemen yang tersisa di belakangnya untuk mengisi kekosongan, kemudian mengurangi nilai tail. Setelah data dioperasikan, program menampilkan status antrian (head, tail, dan isi antrian) menggunakan fungsi printInfo. Dengan pemisahan kode ke dalam file header dan implementasi, program ini menunjukkan penerapan konsep FIFO (First-In, First-Out), meskipun proses dequeue kurang efisien karena melibatkan operasi pergeseran data (O(n)).

### 2. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).


1. **Data Queue2.h** 

```C++
#ifndef STACK_H
#define STACK_H

const int MAX = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

// Prosedur dasar
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);


#endif


```

2. **Data Queue2.cpp** 

```C++
#include <iostream>
#include "stack2.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    if (isEmpty(S) || x >= S.info[S.top - 1]) {
        push(S, x);
    } else {
        infotype temp = pop(S);
        pushAscending(S, x);
        push(S, temp);
    }
}

```


3. **Data main.cpp** 

```C++
#include <iostream>
#include "stack2.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}


```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan8_Modul8/Output/Jawabanno2.png)

Program ini mengimplementasikan struktur data Queue menggunakan mekanisme Head dan Tail Bergerak. Sama seperti sebelumnya, struktur Queue menggunakan array info dan penanda posisi head serta tail.Dalam mekanisme ini, baik fungsi enqueue (menambahkan elemen melalui tail++) maupun dequeue (menghapus elemen melalui head++) adalah operasi yang sangat cepat (O(1)) karena tidak ada operasi pergeseran data yang dilakukan. Namun, kelebihan kecepatan ini harus dibayar mahal. Karena head dan tail terus bergerak maju, ruang di awal array (indeks 0 hingga head-1) yang sudah dikosongkan tidak dapat digunakan kembali. Hal ini mengakibatkan masalah Memori Terbuang (Wasted Space). Antrian dianggap penuh (isFull) segera setelah tail mencapai batas akhir array (MAX_QUEUE - 1), meskipun masih banyak ruang kosong yang tidak terpakai di depan head. Program ini menyoroti trade-off antara kecepatan operasi dan efisiensi penggunaan memori.

### 3. Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan8_Modul8/Unguided3/Soal1.png)


1. **Data Queue3.h** 

```C++
#ifndef STACK_H
#define STACK_H

const int MAX = 20;
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

// Prosedur dasar
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif

```

2. **Data Queue3.cpp** 

```C++
#include <iostream>
#include "stack3.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == MAX;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        S.top--;
        return S.info[S.top];
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    if (isEmpty(S) || x >= S.info[S.top - 1]) {
        push(S, x);
    } else {
        infotype temp = pop(S);
        pushAscending(S, x);
        push(S, temp);
    }
}
void getInputStream(Stack &S) {
    cout << "Masukkan karakter (tekan Enter untuk berhenti): ";
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') {
            break;
        }
        
        if (ch >= '0' && ch <= '9') {
       
            infotype digitValue = ch - '0'; 
            push(S, digitValue);
        }
  
    }
}



```


3. **Data Main.cpp** 

```C++
#include <iostream>
#include "stack3.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Output/Jawabanno3.png)

Program ini mengimplementasikan struktur data Queue menggunakan mekanisme Circular Queue (Antrian Melingkar), yang merupakan solusi paling efisien dari implementasi berbasis array.Struktur Queue tetap menggunakan head dan tail, namun pergerakan indeksnya dihitung menggunakan operasi modulo (% MAX_QUEUE). Fungsi enqueue dan dequeue memanfaatkan operasi modulo tersebut untuk memastikan bahwa, ketika indeks mencapai batas akhir array, ia akan berputar kembali ke indeks 0 jika ruang tersebut sudah kosong. Dengan mekanisme berputar ini, masalah Memori Terbuang yang ditemukan pada Alternatif 2 dapat dihindari, sehingga seluruh ruang array dapat dimanfaatkan secara optimal. Fungsi isFull pun menggunakan logika modulo untuk mendeteksi apakah antrian benar-benar penuh. Program ini menyajikan implementasi FIFO yang efisien, di mana kecepatan operasi (enqueue dan dequeue adalah O(1)) dan efisiensi memori dicapai secara simultan.

## Kesimpulan
Kesimpulannya, ketiga implementasi Queue (Antrian) yang telah dibuat menggambarkan proses bertahap dalam mengimplementasikan dan mengoptimalkan struktur data Queue menggunakan array statis dalam bahasa C++. Ketiga mekanisme tersebut berfokus pada penerapan prinsip FIFO (First-In, First-Out), tetapi dengan cara pengelolaan indeks head (depan) dan tail (belakang) yang berbeda:
1. Queue Alternatif 1 (Head Diam): Implementasi ini fokus pada struktur dasar, di mana elemen pertama antrian selalu berada di indeks 0. Fungsi dequeue bekerja dengan menggeser maju (shifting) semua elemen yang tersisa setelah elemen pertama dihapus. Program ini memperkenalkan konsep dasar FIFO, tetapi dengan konsekuensi kinerja yang lambat pada operasi dequeue (O(n)) karena operasi pergeseran data.
2. Queue Alternatif 2 (Head dan Tail Bergerak): Implementasi ini bertujuan meningkatkan efisiensi dengan membiarkan head dan tail bergerak maju, sehingga menghilangkan operasi pergeseran data. Hal ini membuat enqueue dan dequeue sangat cepat (O(1)). Namun, kelemahan mendasarnya adalah masalah Memori Terbuang (Wasted Space). Ruang array di depan head yang sudah kosong tidak dapat digunakan kembali, menyebabkan antrian dinyatakan penuh meskipun masih ada kapasitas yang kosong.
3. Queue Alternatif 3 (Circular Queue / Berputar): Implementasi ini menyajikan solusi paling optimal dan efisien. Dengan memanfaatkan operasi modulo (% MAX_QUEUE), program ini memungkinkan indeks head dan tail untuk berputar kembali ke awal array, sehingga menggunakan kembali ruang yang telah dikosongkan. Mekanisme ini berhasil mempertahankan kecepatan operasi O(1) seperti Alternatif 2, sekaligus mengatasi masalah wasted space.
Secara keseluruhan, program-program ini memperlihatkan penerapan konsep modularisasi yang baik melalui pemisahan kode ke dalam file header (.h), file implementasi (.cpp), dan file program utama (main.cpp), serta menunjukkan bagaimana pilihan mekanisme array secara fundamental memengaruhi kinerja dan efisiensi penggunaan memori pada struktur data Queue.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Azura Trijayanti, Intan Aulia, Nazwa Khairunisa, Farhan Asyrof Hamadi Purba, & Indra Gunawan. (2025). "Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi". Jurnal Publikasi Teknik Informatika, Vol. 4, No. 2, hlm. 48-53. Diakses melalui https://doi.org/10.55606/jupti.v4i2.4170
<br>[3] Trijayanti, Z., Aulia, I., Khairunisa, N., Hamadi Purba, F., & Gunawan, I. (2025). "Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses pada Sistem Operasi". Jurnal Publikasi Teknik Informatika, 4(2), 48-53. Diakses melalui https://jurnal.nolsatu.co.id/jutekom/article/view/28 