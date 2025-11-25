#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

const int MAX = 5;

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head, Tail;
};

void createQueue(QueueEkspedisi &Q);
bool isEmpty(const QueueEkspedisi &Q);
bool isFull(const QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, const Paket &p);
void deQueue(QueueEkspedisi &Q);
void viewQueue(const QueueEkspedisi &Q);
long long TotalBiayaPengiriman(const QueueEkspedisi &Q);

#endif
