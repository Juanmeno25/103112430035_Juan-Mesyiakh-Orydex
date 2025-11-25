#include "Pengiriman.h"
using namespace std;

void createQueue(QueueEkspedisi &Q) {
    Q.Head = 0;
    Q.Tail = -1;
}

bool isEmpty(const QueueEkspedisi &Q) {
    return Q.Tail == -1;
}

bool isFull(const QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

void enQueue(QueueEkspedisi &Q, const Paket &p) {
    if (isFull(Q))
        cout << "\nQueue penuh.\n";
    else {
        Q.dataPaket[++Q.Tail] = p;
        cout << "\nPaket " << p.KodeResi << " ditambahkan.\n";
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q))
        cout << "\nQueue kosong.\n";
    else {
        cout << "\nPaket " << Q.dataPaket[0].KodeResi << " dihapus.\n";
        for (int i = 0; i < Q.Tail; i++)
            Q.dataPaket[i] = Q.dataPaket[i + 1];
        Q.Tail--;
    }
}

void viewQueue(const QueueEkspedisi &Q) {
    cout << "\nIsi Queue Paket Komaniya Ekpress (Head=" << Q.Head << ", Tail=" << Q.Tail << ")\n";
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
    } else {
        cout << left << setw(5)  << "No."
     << setw(12) << "Resi"
     << setw(15) << "Pengirim"
     << setw(10) << "Berat"
     << setw(15) << "Tujuan" << "\n";

for (int i = Q.Head; i <= Q.Tail; i++) {
    cout << left << setw(5)  << i + 1
         << setw(12) << Q.dataPaket[i].KodeResi
         << setw(15) << Q.dataPaket[i].NamaPengirim
         << setw(10) << (to_string(Q.dataPaket[i].BeratBarang) + " kg")
         << setw(15) << Q.dataPaket[i].Tujuan
         << "\n";
        }
    }
}

long long TotalBiayaPengiriman(const QueueEkspedisi &Q) {
    const long long BIAYA_PER_KG = 8250;
    long long totalBerat = 0;

    for (int i = Q.Head; i <= Q.Tail; i++)
        totalBerat += Q.dataPaket[i].BeratBarang;

    return totalBerat * BIAYA_PER_KG;
}
