#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef struct {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
} Mahasiswa;

const int MAX = 6;

typedef struct {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
} StackMahasiswa;
bool isEmpty(StackMahasiswa& StackMHS);
bool isFull(StackMahasiswa& StackMHS);
void createStack(StackMahasiswa& StackMHS);
void Push(StackMahasiswa& StackMHS, Mahasiswa data);
Mahasiswa Pop(StackMahasiswa& StackMHS);
void Update(StackMahasiswa& StackMHS, int posisi, Mahasiswa dataUpdate);
void View(StackMahasiswa& StackMHS);
void SearchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);
float hitungNilaiAkhir(float tugas, float uts, float uas);
void ProsedurMaxNilaiAkhir(StackMahasiswa& StackMHS);

#endif