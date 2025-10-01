# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori
Bahasa C++ merupakan bahasa pemrograman berorientasi objek yang juga mendukung paradigma prosedural. Pada tahap lanjutan, pemahaman terhadap fungsi, array, dan pointer sangat penting karena ketiganya merupakan fondasi dalam pengelolaan data dan struktur program.

1. **Fungsi (Function)**  
    Fungsi dalam C++ digunakan untuk memecah program menjadi bagian-bagian yang lebih kecil dan modular. Dengan fungsi, kode menjadi lebih mudah dipahami, dipelihara, dan digunakan kembali. Pemanfaatan fungsi juga membantu dalam konsep divide and conquer dalam pemrograman.

2. **Array**
    Array adalah kumpulan variabel dengan tipe data yang sama yang disimpan secara berurutan di memori. Array memungkinkan penyimpanan dan pengolahan data dalam jumlah besar secara efisien. Dalam pemrograman modern, array sering dipadukan dengan pointer untuk optimasi.

3. **Pointer**
    Pointer adalah variabel yang menyimpan alamat memori. Konsep pointer penting untuk memahami cara kerja memori komputer dan manajemen data dalam C++. Dengan pointer, pemrogram dapat mengakses dan memanipulasi data secara langsung di memori, serta mendukung pemrograman dinamis melalui dynamic memory allocation.
4. **Parameter by Value dan Parameter by Reference**
    Dalam C++, fungsi dapat menerima argumen dengan dua cara, yaitu by value (nilai variabel disalin ke parameter) dan by reference (parameter berisi alamat memori variabel). Konsep ini penting dalam efisiensi pengolahan data karena by reference menghindari penyalinan data besar.

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
### C. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama.
Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen.

   ```cpp
#include <iostream>
using namespace std;

int main (){
int arr[5];

for (int i = 0; i < 5; i++){
    cout << "masukan value index ke-" << i << " : ";
    cin >> arr[i];
  }
  int j = 0;
  while (j < 5){
     cout << "isi index ke-" << j << " : " << arr[j] << endl;
     j++;
   }
  return 0;

}

   ```

---

### D. Pointer<br/>
Pointer merupakan dasar tipe variabel yang berisi integer dalam format heksadesimal. Pointer
digunakan untuk menyimpan alamat memori variabel lain sehingga pointer dapat mengakses nilai dari
variabel yang alamatnya ditunjuk.
  
   ```cpp
#include <iostream>
using namespace std;

int main (){
int arr[] = {10, 20, 30, 40, 50};
int*ptr = arr;

for(int i = 0; i < 5; ++i){
    cout << "Element array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }
    for(int i = 0; i < 5; ++i){
    cout << "Element array ke-" << i+1 << " menggunakan index : " << arr[i] << endl;
    }
    return 0;
}
   ```
### E. Refrensi<br/>
Pemanggilan dengan referensi merupakan cara untuk melewatkan alamat suatu variabel kedalam
suatu fungsi. Dengan cara ini dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam
fungsi. Jadi cara ini dapat mengubah variabel yang ada diluar fungsi.
  
   ```cpp
#include <iostream>
using namespace std;

void ubahNilai(int& ref) {
    ref = 20;
}

int main (){
     int x = 10;
    cout << "Nilai sebelum diubah : " << x << endl;

    ubahNilai(x);
    cout << "Nilai setelah diubah : "<< x << endl;
    return 0;
}
   ```
## Guided 

### 1. Array 1 Dimensi

```C++
#include <iostream>
using namespace std;

int main (){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukan value index ke-" << i << " : ";
         cin >> arr[i];
    }
    int j = 0;
    while (j < 5){
       cout << "isi index ke-" << j << " : " << arr[j] << endl;
       j++;
    }
    return 0;

}

```
Program diatas merupakan arrai 1 dimensi. 

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };

    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };

    cout << "Isi array A:" << endl;
    tampilArray(arrA);

    cout << endl << "Isi array B:" << endl;
    tampilArray(arrB);

    int arrC[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << endl << "Hasil penjumlahan array A + B:" << endl;
    tampilArray(arrC);

    return 0;
}
```
Program diatas merupakan array 2 dimensi, dengan menggunakan penjumlahan matrix 2*2.

### 3. Pointer

```C++
#include <iostream>
using namespace std;

void ubahNilai(int* ptr){
    *ptr = 20;
}

int main (){
    int x = 10;
    cout << "Nilai sebelum diubah : " << x << endl;

    ubahNilai(&x);
    cout << "Nilai setelah diubah : "<< x << endl;
    return 0;
}    
```
Program diatas merupakan pointer, yang dimana kita tahu nilai awalnya adalah 20, lalu diganti/diubah menjadi 10.

### 4. Prosedure

```C++
#include<iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program diatas merupakan program prosedure, yang dimana memperoleh hasil/ outpunya kita bisa menginputkan 5 array.
 

## Unguided 

### 1. Buatlah program yang berisi 2 matrix 3*3 yang sudah ditentukan nilainya dengan hasil outputnya adalah memilih menu yang sudah ada dan keluar hasil penjumlahan, pengurangan, perkalian dan keluar.

```C++
#include <iostream>
using namespace std;

void tampilkanhasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void penjumlahan(int A[3][3], int B[3][3]){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "Tampilkan hasil penjumlahan : " << endl;
    tampilkanhasil(c); 
}
void pengurangan(int A[3][3], int B[3][3]){
    int c[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            c[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "Tampilkan hasil pengurangan : " << endl;
    tampilkanhasil(c); 
}
void perkalian(int A[3][3], int B[3][3]){
    int c[3][3] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Tampilkan hasil perklian : " << endl;
    tampilkanhasil(c); 
}
int main (){
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
    switch (pilihan) {
        case 1:
        penjumlahan(arrA, arrB);
        break;
        case 2:
        pengurangan(arrA, arrB);
        break;
        case 3:
        perkalian(arrA, arrB);
        break;
        case 4:
        cout << "Program rampung." << endl;
        break;
        default:
        cout << "Pilihan tidak ada."<< endl;
        } 
    } while (pilihan != 4);
return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan1_Modul1/Output/1.png)

Program ini digunakan untuk menghitung operasi dasar matriks berukuran 3x3. Ada tiga fungsi utama yaitu penjumlahan, pengurangan, dan perkalian matriks. Setiap operasi menyimpan hasilnya di matriks baru lalu ditampilkan dengan fungsi tampilkanhasil. Di bagian utama program sudah disediakan dua matriks arrA dan arrB, kemudian ditampilkan menu agar pengguna bisa memilih operasi yang diinginkan. Program akan terus berjalan menggunakan perulangan do-while sampai pengguna memilih keluar.

### 2. Buatlah sebuah program menghitung luas dan keliling dengan nilai awal yang sudah ditentukan, lalu di ubah dengan nilai akhir dan hitung lagi luas dan kelilingnya

```C++
#include <iostream>
using namespace std;

void ubahPanjangLebar(int& Panjang, int& Lebar) {
    Panjang = 12;
    Lebar = 6;
}
int main (){
    int panjang = 10, lebar = 5, luas = 0;
    int keliling;
    cout << "--- Nilai awal---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "lebar   : " << lebar << endl;

    luas = panjang * lebar;
    keliling = 2 * (panjang + lebar);

    cout << "---Hasil Perhitungan Awal---" << endl;
    cout << "Luas     : " << luas << endl;
    cout << "Keliling : " << keliling << endl;

    ubahPanjangLebar(panjang, lebar);

    luas = panjang * lebar;
    keliling = 2 * (panjang + lebar);

    cout << "---Hasil Yang Baru---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "lebar   : " << lebar << endl;
    cout << "Luas     : " << luas << endl;
    cout << "Keliling : " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan1_Modul1/Output/2.png)

Program ini menghitung luas dan keliling persegi panjang, lalu mengubah nilai panjang dan lebar dengan fungsi. Awalnya, panjang = 10 dan lebar = 5. Luas dihitung dengan rumus panjang * lebar, keliling dengan 2 * (panjang + lebar). Hasil awal ditampilkan. Kemudian dipanggil fungsi ubahPanjangLebar yang menggunakan reference sehingga langsung mengubah nilai panjang menjadi 12 dan lebar menjadi 6. Setelah itu luas dan keliling dihitung ulang dengan nilai baru dan ditampilkan lagi. Intinya, program ini menunjukkan cara kerja parameter reference di C++ untuk mengubah nilai variabel langsung dari dalam fungsi, lalu membandingkan hasil perhitungan sebelum dan sesudah perubahan.