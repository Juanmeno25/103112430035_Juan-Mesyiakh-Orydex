# <h1 align="center">Laporan Praktikum Modul 8  -  Binary Search Tree </h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori

Binary Tree atau Pohon Biner adalah struktur data berbentuk hierarki dengan hubungan one-to-many. Setiap simpul memiliki maksimal dua anak, yaitu anak kiri dan anak kanan. Secara umum, binary tree digunakan untuk merepresentasikan data yang bercabang dan tersusun dalam beberapa level dari root.
   **Binary Search Tree**  
  Binary Search Tree (BST) adalah bentuk khusus dari binary tree yang terurut. BST menyimpan data berupa bilangan atau nama dengan aturan: nilai yang lebih kecil ditempatkan di anak kiri, dan nilai yang lebih besar di anak kanan. Karena sifat pengurutannya, BST sering digunakan untuk penyimpanan dan pencarian data yang lebih efisien di dalam memori.


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

### C. Rekrusif
rekursif berarti proses yang memanggil dirinya sendiri. Dalam pemrograman, prosedur dan fungsi rekursif digunakan untuk menyelesaikan masalah yang bentuknya berulang. Subprogram membantu membuat program lebih mudah dibaca, lebih terstruktur karena terbagi menjadi bagian-bagian kecil, dan dapat digunakan kembali tanpa harus menulis ulang kode yang sama. Subprogram rekursif akan terus memanggil dirinya sendiri selama kondisi tertentu masih terpenuhi, mirip dengan prinsip induksi matematika. Salah satu contoh paling sederhana adalah fungsi rekursif untuk menghitung nilai pangkat dua.

  ```cpp
#include <iostream>
using namespace std;

int pangkat_2(int x) {
    // Basis
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x - 1);
    }
}
int main() {
    cout << "=====REKRUSIF PANGKAT 2=====" << endl;
    int x;
    cout << "Masukkax xilai x: ";
    cin >> x;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x) << endl;
    return 0;
}

   ```

### D. Bstree
Tree merupakan struktur data berbentuk graf tak berarah yang terhubung dan tidak memiliki sirkuit, sehingga setiap node hanya terhubung melalui satu jalur tanpa membentuk lingkaran.


   ```cpp
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

   ```
## Guided 

### 1. Rekrusif

```C++
#include <iostream>
using namespace std;

int pangkat_2(int x) {
    // Basis
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x - 1);
    }
}
int main() {
    cout << "=====REKRUSIF PANGKAT 2=====" << endl;
    int x;
    cout << "Masukkax xilai x: ";
    cin >> x;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x) << endl;
    return 0;
}

```

### 2. Bstree 1
1. **Data BST1.h** 

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;
typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
#endif

```
BST1.h ini berisi struktur data dan deklarasi fungsi yang digunakan untuk mengelola struktur data Binary Search Tree (BST). File ini tidak memuat implementasi fungsi secara langsung, melainkan hanya mendefinisikan tipe data, struktur node untuk tree, serta prototipe fungsi-fungsi seperti pembuatan tree, penambahan node, traversal, perhitungan jumlah node, dan kedalaman tree, yang nantinya akan diimplementasikan pada file .cpp lainnya.
2. **Data Queue.cpp** 

```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
File BST1.cpp ini berisi implementasi dari seluruh fungsi yang telah dideklarasikan pada file BST1.h. Di dalamnya terdapat fungsi untuk mengecek apakah tree kosong, membuat tree baru, mengalokasikan node, dan memasukkan data ke dalam Binary Search Tree sesuai aturan BST. File ini juga mengimplementasikan tiga jenis traversal (preOrder, inOrder, postOrder) yang digunakan untuk menampilkan isi tree dalam urutan tertentu. Selain itu, terdapat fungsi utilitas untuk menghitung jumlah node yang ada dalam tree serta menentukan kedalaman atau tinggi tree. Semua proses pengelolaan BST dilakukan di file ini, sementara struktur data dan deklarasi fungsinya berada pada file header.
3. **Data Main.cpp** 

```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
File main.cpp ini berfungsi sebagai program utama untuk menjalankan dan menguji operasi pada Binary Search Tree (BST). Di dalamnya dilakukan pembuatan tree, kemudian penyisipan beberapa data menggunakan fungsi insertNode. Program ini juga menampilkan hasil traversal InOrder, PreOrder, dan PostOrder untuk menunjukkan urutan penelusuran node pada BST. Selain itu, main.cpp memanggil fungsi countNodes untuk menghitung jumlah node yang ada dalam tree serta treeDepth untuk mengetahui kedalaman atau tinggi tree. File ini hanya berperan sebagai penguji dan pengguna fungsi-fungsi BST yang telah didefinisikan di BST1.h dan diimplementasikan pada file BST1.cpp.

### 3. Bstree 2
1. **Data BST2.h** 

```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;
typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};
bool isEmpty(address root);
void createTree(address &root);
address newNode(infotype x);
address insertNode(address root, infotype x);
void preOrder(address root);
void inOrder(address root);
void postOrder(address root);
int countNodes(address root);
int treeDepth(address root);
void searchByData(address root, infotype x);
address mostLeft(address root);
address mostRight(address root);
bool deleteNode(address &root, infotype x);
void deleteTree(address &root);
#endif
```
File BST1.h ini berisi struktur data dan deklarasi fungsi yang digunakan untuk mengelola struktur data Binary Search Tree (BST). File ini tidak memuat implementasi fungsi secara langsung, melainkan hanya mendefinisikan tipe data, struktur node, serta prototipe berbagai operasi BST seperti pengecekan tree kosong, pembuatan tree, penambahan node, traversal (preorder, inorder, postorder), pencarian data, pengambilan node paling kiri dan paling kanan, penghapusan node, penghapusan seluruh tree, serta perhitungan jumlah node dan kedalaman tree. Seluruh fungsi tersebut akan diimplementasikan pada file .cpp lainnya.
2. **Data Queue.cpp** 

```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
File BST2.cpp ini berisi implementasi seluruh fungsi yang dideklarasikan pada BST2.h. Di dalamnya terdapat kode untuk membuat tree, menambah node, traversal, menghitung jumlah node dan kedalaman, melakukan pencarian data lengkap dengan parent-sibling-child, mendapatkan node terkecil dan terbesar, menghapus node dengan berbagai kondisi, serta menghapus seluruh tree. Semua logika BST dijalankan di file ini, sementara struktur dan deklarasinya ada di file header.

3. **Data Main.cpp** 

```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}

```
File main.cpp ini berfungsi sebagai program utama untuk menguji seluruh fitur Binary Search Tree (BST) yang telah diimplementasikan pada BST2.cpp. Program ini membuat tree, menambahkan beberapa node, menampilkan hasil traversal, menghitung jumlah node dan kedalaman tree, melakukan pencarian data beserta informasi parent-sibling-child, menampilkan node terkecil dan terbesar, menghapus node sesuai input user, serta menghapus seluruh tree. File ini hanya menjalankan dan mendemonstrasikan fungsi-fungsi BST, bukan mengimplementasikan logikanya.


## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file "bstree.h":
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Unguided1/Soal1.png)

### Buatlah implementasi ADT Binary Search Tree pada file "bstree.cpp" dan cobalah hasil implementasi ADT pada file "main.cpp"
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Unguided1/Soal2.png)

1. **Data Tree1.h** 

```C++
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

typedef Node* address;

void createTree(address &root);
address createNode(int x);
address insertNode(address root, int x);
void printInOrder(address root);

#endif




```

2. **Data Tree1.cpp** 

```C++
#include "Tree1.h"

void createTree(address &root) {
    root = NULL;
}

address createNode(int x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

address insertNode(address root, int x) {
    if (root == NULL) {
        return createNode(x);
    }
    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else {
        root->right = insertNode(root->right, x);
    }
    return root;
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

```


3. **Data main.cpp** 

```C++
#include "Tree1.h"

int main() {
    cout << "Hello world!" << endl;

    address root;
    createTree(root);

    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);

    printInOrder(root);

    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Output/Jawabanno1.png)

Program ini digunakan untuk mengelola data bertipe bilangan bulat menggunakan struktur data Binary Search Tree (BST) dalam bahasa C++. Pada file header (BST.h), didefinisikan struktur node yang terdiri dari sebuah nilai info serta pointer left dan right sebagai penunjuk anak kiri dan kanan. File ini juga memuat deklarasi fungsi untuk membuat tree, membuat node baru, menyisipkan node ke dalam BST, dan menampilkan isi tree dengan traversal InOrder. Pada file implementasi (Tree1.cpp), fungsi createTree menginisialisasi tree kosong dengan menjadikan root bernilai NULL, sedangkan createNode digunakan untuk membuat node baru yang siap dimasukkan ke dalam tree. Fungsi insertNode bekerja secara rekursif untuk menempatkan data di posisi yang tepat sesuai aturan BST, yaitu nilai yang lebih kecil ditempatkan ke subtree kiri, dan nilai lebih besar ke subtree kanan. Selanjutnya, fungsi printInOrder menampilkan isi tree dengan urutan kiri–root–kanan sehingga hasil output selalu terurut secara ascending. Pada file main.cpp, program membuat tree kosong, kemudian melakukan serangkaian penyisipan angka (4, 2, 6, 1, 3, 5, 7) sehingga membentuk BST yang seimbang. Setelah seluruh data disisipkan, program memanggil printInOrder untuk menampilkan isi tree dalam kondisi sudah terurut. Secara keseluruhan, program ini menunjukkan cara membangun, mengisi, dan menampilkan Binary Search Tree menggunakan pendekatan rekursif serta pemisahan kode menjadi file header, implementasi, dan main untuk menjaga modularitas program.

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
#### 1. fungsi hitungJumlahNode( root:address ) : integer fungsi mengembalikan integer banyak node yang ada di dalam BST
#### 2. fungsi hitungTotalInfo( root:address, start:integer ) : integer fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST
#### 3. fungsi hitungKedalaman( root:address, start:integer ) : integer fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Unguided2/Soal1.png)


1. **Data Tree2.h** 

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printInOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif



```

2. **Data Tree2.cpp** 

```C++
#include "Tree2.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL) return 0;
    int leftDepth = hitungKedalaman(root->left);
    int rightDepth = hitungKedalaman(root->right);
    return 1 + max(leftDepth, rightDepth);
}

```

### 3. main.cpp
```C++
#include <iostream>
#include "Tree2.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);
    cout << endl << endl;

    cout << "kedalaman : " << hitungKedalaman(root) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;

    return 0;
}


```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Output/Jawabanno2.png)

Program ini mengelola data bilangan bulat menggunakan Binary Search Tree (BST). File Tree2.h berisi struktur node dan deklarasi fungsi untuk membuat node, menambah data, menampilkan tree secara InOrder, serta menghitung jumlah node, total nilai, dan kedalaman tree. Pada Tree2.cpp, fungsi alokasi membuat node baru, insertNode menempatkan data sesuai aturan BST, printInOrder menampilkan data secara terurut, dan tiga fungsi lainnya melakukan perhitungan secara rekursif. Di main.cpp, program membuat root kosong, memasukkan beberapa nilai, lalu menampilkan isi tree beserta kedalamannya, jumlah nodenya, dan total nilainya. Program ini menunjukkan cara menggunakan BST untuk menyimpan dan memproses data secara terurut.

### 3. Print tree secara pre-order dan post-order.
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan10_Modul10/Unguided3/Soal1.png)


1. **Data Tree3.h** 

```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};

// Deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

#endif

```

2. **Data Tree3.cpp** 

```C++
#include "Tree3.h"

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}


void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(address root, infotype x) {
    if (root == NULL) {
        return NULL;
    }
    if (x == root->info) return root;
    else if (x < root->info) return findNode(root->left, x);
    else return findNode(root->right, x);
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

void printPreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " - ";
    }
}


```


3. **Data Main.cpp** 

```C++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    cout << "InOrder   : ";
    printInOrder(root);
    cout << endl;

    cout << "PreOrder  : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}


```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Output/Jawabanno3.png)

Pada file Tree3.h, didefinisikan struktur node yang berisi nilai integer serta pointer menuju anak kiri dan kanan, dan juga deklarasi fungsi untuk membuat node baru, menyisipkan data, mencari data, serta menampilkan tree dengan tiga jenis traversal. Pada file Tree3.cpp, fungsi alokasi digunakan untuk membuat node baru, kemudian insertNode menempatkan nilai ke dalam tree sesuai aturan BST, yaitu data yang lebih kecil ditempatkan pada anak kiri dan data yang lebih besar pada anak kanan. Fungsi findNode digunakan untuk mencari suatu nilai di dalam tree secara rekursif. Tiga fungsi lainnya, yaitu printInOrder, printPreOrder, dan printPostOrder, berfungsi untuk menampilkan isi tree dengan urutan yang berbeda sesuai jenis traversal. Pada main.cpp, program membuat root kosong kemudian memasukkan beberapa data ke dalam BST. Setelah tree terbentuk, program menampilkan isi tree menggunakan ketiga traversal tersebut. Program ini menunjukkan bagaimana BST dapat digunakan untuk menyimpan, mencari, dan menampilkan data secara terstruktur.

## Kesimpulan
Ketiga program tree tersebut sama-sama menunjukkan cara membangun dan menggunakan Binary Search Tree (BST) sebagai struktur data untuk menyimpan dan memproses nilai bilangan bulat. Pada program pertama, fokusnya adalah membuat node, menyisipkan data, dan menampilkan isi BST menggunakan traversal InOrder. Program kedua memperluas fungsionalitas dengan menambahkan perhitungan jumlah node, total nilai, dan kedalaman tree menggunakan rekursi. Program ketiga menambahkan fitur pencarian node serta tiga jenis traversal: InOrder, PreOrder, dan PostOrder. Secara keseluruhan, ketiga program ini memperlihatkan bagaimana BST dapat digunakan untuk memasukkan data secara terurut, menelusuri isi tree dengan berbagai cara, mencari nilai tertentu, serta melakukan perhitungan berbasis struktur tree. BST membantu pengelolaan data menjadi lebih terstruktur, efisien, dan mudah diproses melalui operasi rekursif.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Wulandari, R. (2023). "Implementasi Teknik Binary Search Tree Pada Pencarian Data Penduduk". KAKIFIKOM Journal, Vol. X(?), No. Y(?), hlm. ... . Diakses pada 6 Desember 2025 melalui https://ejournal.ust.ac.id/index.php/KAKIFIKOM/article/view/1794