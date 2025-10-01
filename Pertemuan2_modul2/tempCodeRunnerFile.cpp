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