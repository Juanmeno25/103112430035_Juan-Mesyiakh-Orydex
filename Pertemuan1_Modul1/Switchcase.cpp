#include <iostream>
using namespace std;


   
int main (){
    int angka1, angka2; 
    cout << "Masukan angka : ";
    cin >> angka1;
    cout << "Masukan angka : ";
    cin >> angka2;
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
    cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;
    }

    return 0;
}