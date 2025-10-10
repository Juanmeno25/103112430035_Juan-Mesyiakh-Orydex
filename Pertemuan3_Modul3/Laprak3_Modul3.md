# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman berorientasi objek yang juga mendukung paradigma prosedural. Pada tahap lanjutan, pemahaman terhadap Abstract Data Type (ADT) sangat penting karena Abstract Data Type (ADT) merupakan fondasi dalam pengelolaan data dan struktur program.

   **Abstract Data Type (ADT)**  
    Abstract Data Type (ADT) adalah konsep dasar dalam pemrograman yang menjelaskan tipe data berdasarkan perilaku dan operasi yang bisa dilakukan, bukan berdasarkan cara penyimpanannya di memori. Dengan kata lain, ADT menekankan pada "apa yang dilakukan", bukan "bagaimana cara dilakukan". Abstract Data Type (ADT) adalah dasar dari desain struktur data dan pemrograman berorientasi objek.

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
### C. Abstract Data Type (ADT)<br/>
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK.

   ```cpp
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct Mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(Mahasiswa &m);
float rata2(Mahasiswa m);

#endif

   ```

---

## Guided 

### 1. Abstract Data Type (ADT)
1. **Data Mahasiswa.h** 

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct Mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(Mahasiswa &m);
float rata2(Mahasiswa m);
#endif

```
File .h hanya berisi struktur dan deklarasi fungsi, tanpa menjelaskan cara kerja detailnya. Artinya, pengguna (file main.cpp) hanya tahu bahwa tipe Mahasiswa punya operasi inputMhs dan rata2, tapi tidak tahu bagaimana implementasinya.

2. **Data Mahasiswa.cpp** 

```C++
#include <iostream>
#include "Mahasiswa.h"
using namespace std;

void inputMhs(Mahasiswa &m){
    cout << "input NIM : ";
    cin >> m.nim;
    cout << "input Nilai 1: ";
    cin >> m.nilai1;
    cout << "input Nilai 2";
    cin >> m.nilai2;
}

float rata2(Mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
File Mahasiswa.cpp merupakan implementasi dari ADT Mahasiswa.

3. **Data Main.cpp** 

```C++
#include <iostream>
#include "Mahasiswa.h"
#include <cstdlib>
using namespace std;

int main(){
    Mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata rata nilai adalah : " << rata2 (mhs) << endl;
    system ("Pause");

    return 0;
}
```
File main.cpp merupakan program utama yang menggunakan ADT Mahasiswa.

### 2. Data Struck

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai1, nilai2;
};

void inputMhs(Mahasiswa &m) {
    cout << "Input Nama: ";
    cin >> m.nama; // bisa diganti getline(cin, m.nama) kalau ingin nama lengkap
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(Mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2;
}

int main() {
    Mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");
    return 0;
}
```
Program di atas merupakan implementasi sederhana dari Abstract Data Type (ADT) dalam bahasa C++.
Tipe data Mahasiswa menyatukan data (nama, nilai1, nilai2) dan operasi yang bisa dilakukan terhadap data tersebut (inputMhs() dan rata2()).

## Unguided 

### 1. Buatlah program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uas, tugas, dan nilai akhir. Nilai akhir diperoleh oleh fungsi dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;
     cout << "\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama        : ";
        cin >> mhs[i].nama;
        cout << "NIM         : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;
         cout << "\n";

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "Daftar Nilai Mahasiswa\n"; 
    cout << "\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "UTS         : " << mhs[i].uts << endl;
        cout << "UAS         : " << mhs[i].uas << endl;
        cout << "Tugas       : " << mhs[i].tugas << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "\n";
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan3_Modul3/Output/hasil1.png)

Program ini digunakan untuk menghitung nilai akhir mahasiswa berdasarkan nilai UTS, UAS, dan Tugas. Struktur data struct Mahasiswa digunakan untuk menyimpan informasi setiap mahasiswa, yaitu nama, NIM, nilai UTS, UAS, Tugas, dan Nilai Akhir. Perhitungan nilai akhir dilakukan melalui fungsi hitungNilaiAkhir(), dengan rumus: Nilai Akhir = (0.3 × UTS) + (0.4 × UAS) + (0.3 × Tugas) Di dalam fungsi main(), pengguna diminta memasukkan jumlah mahasiswa (maksimal 10), lalu menginputkan data setiap mahasiswa.
Setelah semua data dimasukkan, program akan menghitung nilai akhir masing-masing mahasiswa dan menampilkan daftar nilai lengkap yang berisi nama, NIM, nilai UTS, UAS, Tugas, dan Nilai Akhir. Dengan demikian, program ini membantu menampilkan hasil akhir penilaian mahasiswa secara otomatis dan rapi.

### 2. Buatlah ADT pelajaran sebagai berikut didalam file ada pelajaran.h
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan3_Modul3/Output/data1.png)
### Buatlah implementasi ADT pelajaran pada file pelajaran.cpp. Cobalah hasil implementasi ADT pada file main.cpp
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan3_Modul3/Output/data2.png)
1. **Data Mahasiswa.h** 

```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodeMapel);

void tampil_pelajaran(pelajaran pel);

#endif
```

2. **Data Mahasiswa.cpp** 

```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodeMapel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodeMapel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai 1 : " << pel.kodeMapel << endl;
}

```


3. **Data Main.cpp** 

```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMapel = "Struktur Data";
    string kodeMapel = "STD";

    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);

    tampil_pelajaran(pel);

    return 0;
}

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan3_Modul3/Output/hasil2.png)

Program ini digunakan untuk menyimpan dan menampilkan data pelajaran dengan konsep modularisasi menggunakan file header (.h) dan file implementasi (.cpp). Struktur data struct pelajaran menyimpan dua informasi yaitu namaMapel dan kodeMapel. Fungsi create_pelajaran digunakan untuk membuat data pelajaran baru dengan mengisi nama dan kode pelajaran, kemudian mengembalikannya sebagai objek pelajaran. Fungsi tampil_pelajaran digunakan untuk menampilkan data pelajaran yang sudah dibuat. Pada bagian main, program membuat satu data pelajaran dengan nama "Struktur Data" dan kode "STD", kemudian menampilkannya ke layar. Program ini menunjukkan cara pembuatan dan penampilan data menggunakan struct serta pemisahan file header dan implementasi dalam C++.

### 3. Buatlah program dengan ketentuan :
1. **2 buah array 2D integer berukuran 3 * 3 dan 2 pointer integer.** 
2. **Fungsi/prosedur yang menampilkan isi sebuah array integer 2D.** 
3. **Fungsi/prosedure yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu.** 
4. **Fungsi/prosedure yang akan menukarkan isi dari variable yang ditunjuk oleh 2 pointer.** 
```C++
#include <iostream>
using namespace std;

const int BARIS = 3;
const int KOLOM = 3;

void tampilArray(int arr[BARIS][KOLOM]) {
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[BARIS][KOLOM], int arr2[BARIS][KOLOM], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

int main() {
    int array1[BARIS][KOLOM] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[BARIS][KOLOM] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };


    int *p1, *p2;
    int baris, kolom;

    cout << "Array 1 awal:\n";
    tampilArray(array1);
    cout << "\nArray 2 awal:\n";
    tampilArray(array2);

    cout << "\nMasukkan baris yang ingin ditukar (0-2): ";
    cin >> baris;
    cout << "Masukkan kolom yang ingin ditukar (0-2): ";
    cin >> kolom;

    p1 = &array1[baris][kolom];
    p2 = &array2[baris][kolom];

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "\nSetelah pertukaran posisi [" << baris << "][" << kolom << "]:\n";
    cout << "Array 1:\n";
    tampilArray(array1);
    cout << "\nArray 2:\n";
    tampilArray(array2);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan3_Modul3/Output/hasil3.png)

Program ini digunakan untuk menukar elemen dari dua array dua dimensi (3x3) pada posisi yang ditentukan oleh pengguna. Program memiliki dua array, yaitu array1 dan array2, yang masing-masing berisi angka berbeda. Fungsi tampilArray digunakan untuk menampilkan isi array dalam bentuk matriks, sedangkan fungsi tukarElemen digunakan untuk menukar elemen antara dua array berdasarkan indeks baris dan kolom yang dimasukkan. Pada bagian utama (main), program pertama menampilkan isi kedua array sebelum pertukaran, kemudian meminta pengguna memasukkan posisi baris dan kolom yang ingin ditukar. Proses pertukaran dilakukan menggunakan pointer (p1 dan p2) agar dapat langsung mengakses dan menukar nilai pada memori. Setelah itu, program menampilkan hasil pertukaran elemen antara kedua array. Program ini menunjukkan penggunaan array dua dimensi, pointer, serta manipulasi data langsung melalui alamat memori dalam C++.
## Kesimpulan
Pada program pertama (data mahasiswa), ADT digunakan untuk merepresentasikan objek mahasiswa yang memiliki atribut dan operasi tertentu seperti menghitung nilai akhir. Program kedua (data pelajaran) memperlihatkan pemisahan antara deklarasi dan implementasi, yang merupakan ciri penting dari ADT karena pengguna hanya mengetahui apa yang dapat dilakukan tanpa harus tahu bagaimana caranya dilakukan. Sedangkan pada program ketiga (penukaran elemen array 2D), konsep manipulasi data dengan pointer dan array dua dimensi ditunjukkan untuk menukar elemen secara langsung melalui alamat memori. Secara keseluruhan, ketiga program ini memperkuat pemahaman bahwa dalam pemrograman C++, ADT memungkinkan pengembang untuk mengorganisasi data dan operasi secara terpisah, menjaga enkapsulasi logika, serta meningkatkan efisiensi dan fleksibilitas dalam pengelolaan data kompleks.
## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2]Nugroho, A. Y., & Sutanto, N. H. (2024). Exploring the Code Foundation: A Literature Review of Data Structures in C++. International Journal of Modern Information and Computer Science Education (IJMICSE). Diperoleh dari: https://international.aritekin.or.id/index.php/IJMICSE/article/view/47
<br>[3]Setiyawan, R. D., Hermawan, D., Abdillah, A. F., & Mujayanah, A. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2). Diperoleh dari: https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263