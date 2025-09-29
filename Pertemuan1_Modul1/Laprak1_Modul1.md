# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Juan Mesyiakh Orydex - 103112430035</p>

## Dasar Teori
Bahasa pemrograman secara umum terbagi menjadi dua, yaitu bahasa tingkat tinggi dan bahasa tingkat rendah. Bahasa tingkat tinggi lebih berorientasi pada manusia karena mudah dipahami, biasanya menggunakan kata-kata mirip bahasa Inggris seperti IF atau AND, dengan contoh seperti Pascal, C, C++, dan BASIC. Sementara itu, bahasa tingkat rendah berorientasi pada mesin, menggunakan kode biner atau kode sederhana seperti bahasa rakitan. Bahasa ini sulit dipahami oleh manusia awam, namun menghasilkan eksekusi yang sangat cepat serta bergantung pada mesin yang digunakan. C++ sendiri telah mengalami evolusi melalui standarisasi ANSI dan ISO dengan penambahan berbagai fitur baru. Keistimewaan C++ terletak pada dukungannya terhadap pemrograman berorientasi objek (OOP), sehingga bahasa ini banyak diminati oleh programmer maupun mahasiswa.

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
### C. Percabangan<br/>

1. **If-Else**  
   Digunakan untuk membuat keputusan berdasarkan kondisi.  
   ```cpp
   if (x > y) {
       cout << "x lebih besar" << endl;
   } else if (x < y) {
       cout << "y lebih besar" << endl;
   } else {
       cout << "x dan y sama" << endl;
   }
   ```

2. **Switch-Case**  
   Cocok digunakan jika banyak pilihan.  
   ```cpp
   int pilihan;
   cin >> pilihan;
   switch(pilihan) {
       case 1: cout << "Menu 1"; break;
       case 2: cout << "Menu 2"; break;
       default: cout << "Pilihan salah";
   }
   ```

---

### D. Perulangan<br/>

1. **For Loop**  
   Digunakan jika jumlah iterasi sudah diketahui.  
   ```cpp
   for (int i = 1; i <= 5; i++) {
       cout << i << " ";
   }
   ```

2. **While Loop**  
   Digunakan jika perulangan berdasarkan kondisi.  
   ```cpp
   int j = 5;
   while (j > 0) {
       cout << j << " ";
       j--;
   }
   ```

3. **Do-While Loop**  
   Menjalankan perintah minimal sekali sebelum cek kondisi.  
   ```cpp
   int k = 1;
   do {
       cout << k << " ";
       k++;
   } while (k <= 5);
   ```


## Guided 

### 1. Praktikum belajar materi dasar Pengenalan Basic C++ dari Tutorial Install - Praktek Hello World


```C++
#include <iostream>  
using namespace std;  

int main() {  
    cout << "Hello, World!" << endl;  
    return 0;  
}
```
Program diatas merupakan program awal/ latihan pemula dalam pemograman C++ untuk menghasilkan output "Hello, Word!". 

### 2. Input & Output

```C++
#include <iostream>
using namespace std;

int main (){
    int angka; 
    cout << "Masukan angka : ";
    cin >> angka;
    cout << "Angka yang dimasukan " << angka << endl;
    return 0;
}
```
Program diatas merupakan hasil dari input dan output yang meminta inputan dari pengguna, dan outputnya dari hasil masukan tersebut. 

### 3. Operator Aritmatika

```C++
#include <iostream>
using namespace std;

int main (){
    int angka1, angka2; 
    cout << "Masukan angka : ";
    cin >> angka1;
    cout << "Masukan angka : ";
    cin >> angka2;
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << "Perkalian   : " << angka1 * angka2 << endl;
    cout << "Pembagian   : " << angka1 / angka2 << endl;
    cout << "Sisa bagi   : " << angka1 % angka2 << endl;
    return 0;
}    
```
Program diatas merupakan program operator aritmatika, dengan menggunakan rumus dasar yaitu penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi.

### 4. Percabangan

```C++
#include <iostream>
using namespace std;

int main (){
    int angka1, angka2; 
    cout << "Masukan angka : ";
    cin >> angka1;
    cout << "Masukan angka : ";
    cin >> angka2;

    if (angka1 < angka2) {
        cout << angka1 << " Kurang dari " << angka2 << endl; 
    } else {
        cout << angka1 << " Lebih dari " << angka2 << endl;
    }

     if (angka1 == angka2) {
        cout << angka1 << " Sama dengan " << angka2 << endl; 
    } else if (angka1 != angka2){
        cout << " angka berbeda " << endl;
    }
    int pilihan;
    cout << "Menu" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "Masukan pilihan" << endl;
    cin >> pilihan;

    switch (pilihan){
    case 1:
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
       cout << endl;
        break;
    case 2: 
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    cout << endl
        break;
    }

    return 0;
}  
```
Program diatas merupakan program percabangan, yang dimana untuk hasil outputnya kita bisa memilih menu penjumlahan atau pengurangan.

### 5. Perulangan

```C++
#include <iostream>
using namespace std;

int main (){
    int angka1, angka2; 
    cout << "Masukan angka : ";
    cin >> angka1;

    for(int i = 0; i <= angka1; i++){
        cout << i << " - ";

    }
    cout <<  endl;
    int j = 10;
    while (j >= angka1){
        cout << j << " - ";
        j--;
    }
    cout <<  endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);
    return 0;
}
```
Program diatas merupakan program perulangan yang dimana kita bisa mengulang berapa banyak tergantung dari input user.
 

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main (){
    float data1, data2;

    cout << "masukan angka yang akan dimasukan : ";
    cin >> data1;
    cout << "masukan angka yang akan dimasukan : ";
    cin >> data2;
    cout << "hasil penjumlahan : " << data1 + data2 << endl;
    cout << "hasil pengurangan : " << data1 - data2 << endl;
    cout << "hasil Pembagian   : " << data1 / data2 << endl;
    cout << "hasil Perkalian   : " << data1 * data2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan1_Modul1/Output/Float.png)

Program di atas ditulis menggunakan bahasa C++ dengan tujuan untuk menghitung dan menampilkan hasil operasi aritmetika dasar dari dua bilangan bertipe float. Pertama, program meminta pengguna memasukkan dua angka melalui perintah cin, lalu menyimpannya ke dalam variabel a dan b. Setelah itu, program melakukan perhitungan penjumlahan, pengurangan, dan perkalian, kemudian langsung menampilkan hasilnya ke layar menggunakan cout.

Pada bagian pembagian, program dilengkapi dengan pengecekan sederhana. Jika nilai b tidak sama dengan nol, maka hasil pembagian a / b ditampilkan. Namun, jika b bernilai nol, program menampilkan pesan bahwa pembagian tidak bisa dilakukan karena penyebut bernilai nol. Dengan cara ini, program menghindari kesalahan eksekusi akibat operasi yang tidak valid.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100.

```C++
#include <iostream>
using namespace std;

string angkatulisan(int n) {
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };

    string puluhan[] = {
        "", "", "dua puluh ", "tiga puluh ",
        "empat puluh ", "lima puluh ", "enam puluh ",
        "tujuh puluh ", "delapan puluh ", "sembilan puluh "
    };

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        int puluh = n / 10;
        int sisanya = n % 10;
        if (sisanya == 0) {
            return puluhan[puluh];
        } else {
            return puluhan[puluh] + satuan[sisanya];
        }
    } else if (n == 100) {
        return "seratus";
    }

    return "Bukan angka yang diinginkan (hanya 1 - 100)";
}

int main() {
    int angka;
    cout << "Masukkan angka dari 1 sampai 100 : ";
    cin >> angka;
    cout << "Keluarnya : " << angkatulisan(angka) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan1_Modul1/Output/Tulisan.png)

Program menggunakan array satuan untuk angka 0-19 dan array puluhan untuk angka kelipatan 10 mulai dari 20. Jika angka yang dimasukkan kurang dari 20, hasilnya langsung diambil dari array satuan. Jika antara 20-99, angka dibagi 10 untuk menentukan puluhan dan sisanya dipakai untuk menentukan satuan, kemudian digabungkan menjadi teks. Input dimasukkan lewat cin, dan hasil konversinya ditampilkan dengan cout.

### 3.  Buatlah program yang dapat memberikan input dan output sebagai berikut.
Input: 3
Output:  
```
321 * 123
 21 * 12
  1 * 1
    *
```

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {

        for (int s = 0; s < n - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Juanmeno25/103112430035_Juan-Mesyiakh-Orydex/blob/main/Pertemuan1_Modul1/Output/Nurun.png)

Program ini adalah program C++ yang digunakan untuk menampilkan pola angka simetris dengan tanda bintang di bagian tengah. Cara kerjanya dimulai dari input angka n yang menentukan ukuran tinggi pola. Setelah itu program menggunakan perulangan luar yang berjalan dari n sampai 1 untuk membuat setiap baris pola. Di dalam setiap baris pertama dibuat spasi di sebelah kiri menggunakan perulangan supaya pola terlihat rata dan simetris. Setelah spasi selesai ditampilkan deretan angka menurun dari i sampai 1. 
Kemudian program menuliskan tanda bintang sebagai pemisah bagian kiri dan kanan. Setelah itu ditampilkan lagi deretan angka menaik dari 1 sampai i sehingga terbentuk bentuk segitiga yang simetris dengan bintang di tengah. Setelah semua baris selesai ada tambahan satu baris terakhir berisi spasi penuh lalu sebuah bintang di tengah. Jika misalnya n = 4 maka hasilnya berupa angka menurun di kiri, bintang di tengah, dan angka menaik di kanan, lalu semakin ke bawah jumlah angka semakin berkurang sampai tinggal satu bintang saja.

## Kesimpulan
Kesimpulannya, ketiga program yang dibuat dalam bahasa C++ ini merupakan implementasi dasar dari penggunaan variabel, operasi aritmatika, pernyataan kondisi, serta perulangan untuk menghasilkan output tertentu. Program pertama menunjukkan bagaimana operasi aritmatika dasar seperti penjumlahan, pengurangan, perkalian, dan pembagian dapat dilakukan dengan tipe data float. Program kedua memperlihatkan bagaimana logika percabangan dan array bisa digunakan untuk mengubah angka menjadi bentuk tulisan dalam rentang 0 sampai 100. Program ketiga memperlihatkan bagaimana nested loop dimanfaatkan untuk membentuk pola simetris berupa deretan angka dengan bintang sebagai pemisah di tengah.

## Referensi
[1] Dewi, L. J. Erawati. (2010). "Media Pembelajaran Bahasa Pemrograman C++". Jurnal Pendidikan Teknologi dan Kejuruan (JPTK), Vol. 7, No. 1, hlm. 63-72. Diakses pada 10 Maret 2024 melalui https://ejournal.undiksha.ac.id/index.php/JPTK/article/view/31
<br>[2] W3Schools. (n.d.). C++ Tutorial. Diakses pada 10 Maret 2024 melalui https://www.w3schools.com/cpp/