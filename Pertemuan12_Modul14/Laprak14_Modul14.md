# <h1 align="center">Laporan Praktikum Modul 14  -  Graph </h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori

Graph adalah struktur data non-linier yang merepresentasikan data sebagai jaringan. Struktur ini terdiri dari dua komponen utama:

1. Verteks (V): Simpul atau titik tempat menyimpan data.

2. Edge (E): Garis atau sisi yang menghubungkan antar verteks, menunjukkan adanya keterkaitan.

   **Graph**  
Graph digunakan untuk memodelkan masalah dunia nyata yang memiliki sistem jejaring, seperti pemetaan hubungan di media sosial (Facebook, Instagram) atau jaringan koneksi antar wilayah.


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

### C. Graph
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda
dan Common Lab merupakan node (vertec). Jalan yang menghubungkan tempat Kost dan Common Lab merupakan garis penghubung antara keduanya (edge).

  ```cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode*adrNode;
typedef struct ElmEdge*adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge {
    adrNode node;
    adrEdge next;
};
struct Graph {
    adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

   ```


## Guided 


### 1. Graph
1. **Data graph.h** 

```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode*adrNode;
typedef struct ElmEdge*adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge {
    adrNode node;
    adrEdge next;
};
struct Graph {
    adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif

```
graph.h ini berisi struktur data dan deklarasi fungsi untuk mengelola Graph dengan metode Adjacency List. File ini hanya mendefinisikan tipe data, struktur node (titik) dan edge (sisi), serta prototipe fungsi seperti pembuatan graph, penambahan node, penyambungan antar node, dan penampilan struktur graph yang nantinya akan diimplementasikan pada file .cpp.

2. **Data graph_edge.cpp** 

```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        else {
        P = P->next;
        }
    }
    return NULL;
}


void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge-> node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```
Kode ini mengimplementasikan pencarian dan penghubungan titik dalam graph. Fungsi findNode mencari alamat node berdasarkan datanya, sementara connectNode membuat hubungan satu arah dengan menambahkan Edge baru dari node asal ke node tujuan.

3. **Data graph_init.cpp** 

```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```

Kode ini berisi fungsi dasar untuk membangun struktur graph. createGraph menginisialisasi graph kosong, allocateNode menyiapkan memori dan data untuk node baru, dan insertNode menambahkan node tersebut ke akhir daftar utama graph.


4. **Data graph_print.cpp** 

```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << "Terhuung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
```
Fungsi printGraph ini digunakan untuk menampilkan seluruh isi graph ke layar dengan cara menelusuri setiap node utama dan mencetak daftar node tetangga yang terhubung melalui sisi-sisinya (edge).

5. **Data Main.cpp** 

```C++
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Fungsi main ini merupakan program utama yang mensimulasikan pembuatan graph dengan menginisialisasi graph G, menambahkan empat node (A, B, C, D), dan membangun hubungan antar node tersebut sebelum akhirnya menampilkan seluruh struktur graph ke layar.



## Unguided 

### 1. Buatlah ADT Graph tidak berarah file "graph.h":
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan12_Modul14/Unguided1/Soal1.png)


1. **Data graph1.h** 

```C++
#ifndef GRAPH1_H_INCLUDED
#define GRAPH1_H_INCLUDED
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node; 
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif



```

2. **Data graph1.cpp** 

```C++
#include "graph1.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;
    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

```


3. **Data main.cpp** 

```C++
#include "graph1.h"
int main() {
    Graph G;
    CreateGraph(G);
    InsertNode(G, 'A'); InsertNode(G, 'B'); InsertNode(G, 'C');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    cout << "Struktur Graph Soal 1:" << endl;
    PrintInfoGraph(G);
    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan12_Modul14/Output/Jawabanno1.png)

Pada file graph1.h, didefinisikan struktur ElmNode untuk menyimpan data simpul dan ElmEdge untuk menyimpan hubungan (sisi) antar simpul menggunakan konsep multi linked list, serta deklarasi fungsi dasar graph. Pada file graph1.cpp, fungsi InsertNode digunakan untuk menambah simpul baru ke dalam list utama, sementara ConnectNode berfungsi untuk menghubungkan dua simpul secara timbal balik karena graph bersifat tidak berarah (undirected). Fungsi PrintInfoGraph menampilkan setiap simpul beserta daftar tetangga yang terhubung dengannya. Pada main1.cpp, program menginisialisasi graph, memasukkan tiga simpul (A, B, C), dan menghubungkan mereka sebelum akhirnya menampilkan struktur tersebut ke layar.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS prosedur PrintDFS (Graph G, adrNode N);



1. **Data graph2.h** 

```C++
#ifndef GRAPH2_H_INCLUDED
#define GRAPH2_H_INCLUDED
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);

#endif



```

2. **Data graph2.cpp** 

```C++
#include "graph2.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;
    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;
    cout << N->info << " ";
    N->visited = 1;
    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->Node);
        E = E->Next;
    }
}
```

### 3. main.cpp
```C++
#include "graph2.h"
int main() {
    Graph G; 
    CreateGraph(G);
    InsertNode(G, 'A'); 
    InsertNode(G, 'B'); 
    InsertNode(G, 'C'); 
    InsertNode(G, 'D');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'D'));
    cout << "Hasil Penelusuran DFS: ";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    return 0;
}

```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan12_Modul14/Output/Jawabanno2.png)

Pada file graph2.h, ditambahkan deklarasi fungsi PrintDFS untuk menelusuri graph dan ResetVisited untuk mengulang status kunjungan simpul. Pada file graph2.cpp, fungsi PrintDFS diimplementasikan secara rekursif, di mana program akan mengunjungi satu simpul, menandainya sebagai telah dikunjungi (visited = 1), lalu masuk ke cabang terdalam dari simpul tetangganya sebelum kembali (backtracking). Fungsi ResetVisited sangat krusial untuk memastikan semua simpul dapat diproses kembali dari keadaan nol. Pada main2.cpp, program membangun sebuah jalur linear A-B-C-D dan menampilkan urutan kunjungannya menggunakan algoritma DFS yang dimulai dari simpul A.
### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS prosedur PrintBFS (Graph G, adrNode N);


1. **Data graph3.h** 

```C++
#ifndef GRAPH3_H_INCLUDED
#define GRAPH3_H_INCLUDED
#include <iostream>
#include <queue>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, adrNode N);

#endif
```

2. **Data graph3.cpp** 

```C++
#include "graph3.h"


void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) Q = Q->Next;
        Q->Next = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == NULL || N2 == NULL) return;
    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;
    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}
void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) { P->visited = 0; P = P->Next; }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);
    while (!Q.empty()) {
        adrNode curr = Q.front();
        Q.pop();
        cout << curr->info << " ";
        adrEdge E = curr->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}


```


3. **Data Main.cpp** 

```C++
#include "graph3.h"
int main() {
    Graph G; CreateGraph(G);
    InsertNode(G, 'A'); 
    InsertNode(G, 'B'); 
    InsertNode(G, 'C'); 
    InsertNode(G, 'D');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    cout << "Hasil Penelusuran BFS: ";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    return 0;
}


```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan12_Modul14/Output/Jawabanno3.png)

Pada file graph3.h, disertakan pustaka queue untuk mendukung algoritma BFS serta deklarasi prosedur PrintBFS. Pada file graph3.cpp, fungsi PrintBFS menggunakan bantuan struktur data antrean (queue) untuk mengunjungi simpul lapis demi lapis; dimulai dengan memasukkan simpul awal ke antrean, lalu secara sistematis mengunjungi semua tetangga langsung dari simpul tersebut sebelum pindah ke tingkat yang lebih jauh. Penanda visited digunakan agar tidak terjadi pengulangan kunjungan pada simpul yang sama. Pada main3.cpp, program menguji algoritma ini dengan struktur graph bercabang, yang menunjukkan bahwa BFS akan mendahulukan simpul tetangga terdekat (B dan C) sebelum menuju ke simpul yang lebih jauh (D).

## Kesimpulan
Ketiga program graph tersebut sama-sama menunjukkan cara membangun dan mengelola struktur data Graph Tidak Berarah (Undirected Graph) menggunakan metode Multi Linked List dengan pointer. Pada program pertama, fokus utamanya adalah pembentukan struktur dasar (ADT), mulai dari pengalokasian simpul (node), penyisipan simpul ke dalam list, hingga pembuatan relasi atau sisi (edge) yang menghubungkan dua simpul secara timbal balik. Program kedua memperluas fungsionalitas dengan mengimplementasikan metode penelusuran Depth First Search (DFS), yang bekerja secara rekursif untuk menjelajahi cabang graph sedalam mungkin sebelum melakukan backtracking. Program ketiga melengkapi fitur penelusuran dengan metode Breadth First Search (BFS), yang menggunakan bantuan antrean (queue) untuk mengunjungi simpul lapis demi lapis berdasarkan jarak terdekatnya Secara keseluruhan, ketiga program ini memperlihatkan bagaimana graph dapat digunakan untuk merepresentasikan hubungan kompleks antar data yang tidak hanya bersifat hierarkis. Dengan kombinasi ADT yang dinamis dan algoritma penelusuran (DFS dan BFS), data dalam graph dapat dikelola, dihubungkan, dan diakses kembali secara sistematis. Penggunaan penanda visited pada setiap simpul memastikan proses penelusuran berjalan efisien tanpa terjebak dalam perulangan tak terbatas (infinite loop), sehingga graph menjadi struktur data yang sangat kuat untuk memodelkan jaringan atau keterhubungan antar objek.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Trivusi. (2022). "Struktur Data Graph: Pengertian, Jenis, dan Kegunaannya". Trivusi Web IT, Diakses pada 22 Desember 2025 melalui https://www.trivusi.web.id/2022/07/struktur-data-graph.html