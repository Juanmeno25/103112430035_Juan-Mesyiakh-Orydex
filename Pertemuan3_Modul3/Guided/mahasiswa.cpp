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
