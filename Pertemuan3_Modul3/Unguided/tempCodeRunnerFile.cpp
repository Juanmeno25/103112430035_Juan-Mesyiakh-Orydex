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