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
