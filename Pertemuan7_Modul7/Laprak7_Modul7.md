# <h1 align="center">Laporan Praktikum Modul 7  -  STACK</h1>
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
### C. Stack
Doubly Linked List adalah salah satu jenis struktur data yang berbentuk rangkaian node, di mana setiap node saling terhubung secara dua arah. Setiap node di dalam Doubly Linked List memiliki tiga komponen, yaitu data yang menyimpan informasi, pointer next yang menunjuk ke node berikutnya, dan pointer prev yang menunjuk ke node sebelumnya. Dengan adanya dua pointer tersebut, daftar ini dapat ditelusuri dari dua arah, baik dari awal ke akhir maupun dari akhir ke awal.


   ```cpp
#include <iostream>
#include "stack.h"
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


   ```
## Guided 

### 1. Stack 1 
1. **Data Stack.h** 

```C++
#ifndef STACK.H
#define STACK.H
#define Nil NULL
#include <iostream>
using namespace std;
typedef struct node *address;
struct node{
    int dataAngka;
    address next;
};
struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
File stack.h ini berisi struktur data dan deklarasi fungsi untuk mengelola struktur data Stack menggunakan Linked List (list searah). File ini tidak berisi implementasi fungsi, melainkan hanya deklarasi tipe data dan prototipe fungsi yang akan diimplementasikan di file .cpp lain.

2. **Data Stack.cpp** 

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
File stack.cpp ini berisi implementasi dari fungsi-fungsi yang telah dideklarasikan pada file stack.h. Struktur data yang digunakan adalah Stack (tumpukan) berbasis Linked List dengan konsep LIFO (Last In, First Out), artinya data yang terakhir dimasukkan akan menjadi yang pertama diambil.

3. **Data Main.cpp** 

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
File main.cpp berisi program utama (fungsi main) untuk menguji seluruh operasi stack yang sudah dibuat di stack.cpp. Struktur data stack yang digunakan berbasis linked list, dengan operasi dasar seperti push, pop, update, view, dan searchData.
### 2. Stack 2
1. **Data Stack.h** 

```C++
#ifndef STACK_H
#define MaxEl 20
#define Nil -1
#include <iostream>
typedef int infotype;
typedef struct {
    infotype info[MaxEl];
    int top;
} Stack;
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
File stack.h ini berisi deklarasi struktur data dan fungsi untuk mengelola stack (tumpukan) menggunakan array statis. Struktur stack ini mengikuti prinsip LIFO (Last In, First Out), di mana elemen terakhir yang masuk akan menjadi elemen pertama yang keluar.
2. **Data Stack.cpp** 

```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
File stack.cpp ini berisi implementasi dari operasi dasar Stack (tumpukan) menggunakan array statis berukuran maksimum MaxEl. Struktur data stack bekerja dengan prinsip LIFO (Last In, First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan.

3. **Data Main.cpp** 

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
File main.cpp ini berfungsi sebagai program utama untuk menguji seluruh fungsi yang ada di struktur data Stack berbasis array. Semua operasi dasar stack seperti push, pop, printInfo, dan balikStack digunakan di sini untuk memperlihatkan cara kerja stack dengan prinsip LIFO (Last In, First Out).


## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file "stack.h":
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Unguided1/Soal1.png)

### Buatlah implementasi ADT Stack menggunakan Array pada file "stack.cpp" dan "main.cpp"

![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Unguided1/Soal2.png)

1. **Data Stack1.h** 

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

#endif


```

2. **Data Stack1.cpp** 

```C++
#include <iostream>
#include "stack.h"
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

```


3. **Data main.cpp** 

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}


```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Output/Jawabanno1.png)

Program ini digunakan untuk mengelola data bertipe bilangan bulat (integer) menggunakan struktur data Stack berbasis array dalam bahasa C++. Struktur stack (struct Stack) terdiri dari sebuah array info berukuran maksimum 20 elemen dan sebuah variabel top yang digunakan untuk menunjukkan posisi elemen paling atas di stack. Program diawali dengan pembuatan stack kosong menggunakan fungsi createStack, kemudian dilakukan serangkaian operasi push untuk menambahkan elemen ke atas stack, serta pop untuk menghapus elemen teratas. Setelah beberapa data dimasukkan, program menampilkan isi stack menggunakan fungsi printInfo, yang mencetak elemen dari posisi teratas hingga terbawah. Selain itu, terdapat fungsi balikStack yang digunakan untuk membalik urutan isi stack, yaitu dengan memindahkan semua elemen dari stack utama ke stack sementara, lalu menyalinnya kembali sehingga urutan data menjadi terbalik. Dengan pemisahan kode ke dalam file header (stack.h), implementasi fungsi (file .cpp), dan program utama (main.cpp), program ini menunjukkan penerapan konsep modularisasi dan struktur data tumpukan (stack) yang bekerja dengan prinsip LIFO (Last In, First Out), sehingga pengelolaan data menjadi lebih terstruktur dan efisien.
### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Unguided2/Soal1.png)


1. **Data Stack2.h** 

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

2. **Data Stack2.cpp** 

```C++
#include <iostream>
#include "stack.h"
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


3. **Data Main.cpp** 

```C++
#include <iostream>
#include "stack.h"
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
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Output/Jawabanno2.png)

Program ini mengelola data bilangan bulat menggunakan struktur data Stack berbasis array. Stack memiliki elemen info untuk menyimpan data dan top sebagai penanda posisi teratas. Fungsi dasar seperti push, pop, isEmpty, dan isFull digunakan untuk menambah, menghapus, serta memeriksa kondisi stack. Fungsi pushAscending menambahkan data secara berurutan dari kecil ke besar, menggunakan rekursi agar isi stack selalu terurut. Fungsi balikStack digunakan untuk membalik urutan elemen stack. Program ini menunjukkan penerapan konsep tumpukan, rekursi, dan modularisasi dalam C++ secara efisien.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan7_Modul7/Unguided3/Soal1.png)


1. **Data Stack3.h** 

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

2. **Data Stack3.cpp** 

```C++
#include <iostream>
#include "stack.h"
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
        if (ch == '\n') break;
        push(S, ch);
    }
}



```


3. **Data Main.cpp** 

```C++
#include <iostream>
#include "stack.h"
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

Program ini digunakan untuk mengelola data menggunakan struktur Stack berbasis array dalam bahasa C++. Stack terdiri dari elemen info sebagai tempat penyimpanan data dan top sebagai penanda posisi elemen teratas. Program memiliki beberapa fungsi dasar seperti push, pop, isEmpty, dan isFull untuk menambah, menghapus, dan memeriksa kondisi stack. Selain itu, terdapat fungsi pushAscending yang menambahkan elemen secara terurut naik (ascending) menggunakan teknik rekursi, serta fungsi balikStack yang digunakan untuk membalik urutan elemen di dalam stack.

## Kesimpulan
Kesimpulannya, ketiga program Stack yang telah dibuat menggambarkan proses bertahap dalam memahami dan mengimplementasikan struktur data Stack (tumpukan) menggunakan bahasa C++. Pada program Stack versi pertama, fokus utamanya adalah membangun struktur dasar stack berbasis pointer (linked list), dengan fungsi-fungsi seperti createStack, push, pop, update, view, dan searchData. Program ini memperkenalkan konsep dasar LIFO (Last In, First Out) di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dihapus. Pada program Stack versi kedua, implementasi diperluas dengan menggunakan array statis sebagai media penyimpanan. Fungsi-fungsi dasar seperti push, pop, isEmpty, dan isFull digunakan untuk menambah dan menghapus data, serta memeriksa kondisi stack. Selain itu, ditambahkan fungsi balikStack yang berfungsi untuk membalik urutan elemen di dalam stack menggunakan stack sementara, sehingga memperlihatkan penerapan konsep manipulasi data pada struktur tumpukan. Sementara itu, program Stack versi ketiga mengembangkan fitur yang lebih kompleks, seperti pushAscending untuk menambahkan data secara otomatis dalam urutan menaik (ascending) dengan bantuan rekursi, dan getInputStream yang memungkinkan pengguna memasukkan karakter langsung dari keyboard untuk disimpan ke dalam stack. Program ini juga memperlihatkan penerapan modularisasi yang baik melalui pemisahan antara file header (.h), file implementasi (.cpp), dan file utama (main.cpp).
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] Wijoyo, A., Azzahra, A., Nabila, D., Silviana, F., & Lusiyanti. (2024). Perbandingan struktur linked list dan array dalam manajemen memori. JRIIN: Jurnal Riset Informatika dan Inovasi, 1(12), 1290-1293. Diperoleh dari: https://jurnalmahasiswa.com/index.php/jriin/article/view/957
    