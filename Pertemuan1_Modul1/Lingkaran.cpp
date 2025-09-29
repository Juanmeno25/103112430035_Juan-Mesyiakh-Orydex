#include <iostream>
using namespace std;

int main() {
    float r, luas, keliling;
    const float phi = 3.14;

    cout << "Masukkan jari-jari lingkaran: ";
    cin >> r;

    luas = phi * r * r;
    keliling = 2 * phi * r;

    cout << "Luas lingkaran = " << luas << endl;
    cout << "Keliling lingkaran = " << keliling << endl;

    return 0;
}