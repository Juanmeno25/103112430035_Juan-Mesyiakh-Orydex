#ifndef MAHASISWA_H
#define MAHASISWA_H

//data struck
struct Mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(Mahasiswa &m);
float rata2(Mahasiswa m);
#endif
