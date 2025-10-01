#include <iostream>
using namespace std;

// Fungsi untuk menampilkan array 2 dimensi
void tampilArray(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Array 2 dimensi pertama
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };

    // Array 2 dimensi kedua
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };

    cout << "Isi array A:" << endl;
    tampilArray(arrA);

    cout << endl << "Isi array B:" << endl;
    tampilArray(arrB);

    // Contoh penjumlahan kedua array
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