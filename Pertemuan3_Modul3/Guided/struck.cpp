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
