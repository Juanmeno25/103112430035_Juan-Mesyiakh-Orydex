#include "Pengiriman.h"
using namespace std;

void menu() {
    cout << "\nMENU\n"
         << "1. Buat Queue\n"
         << "2. Input 5 Paket\n"
         << "3. Hapus Paket\n"
         << "4. Tampilkan Queue\n"
         << "5. Hitung Total Biaya\n"
         << "0. Keluar\n"
         << "Pilihan: ";
}

void inputSkenario(QueueEkspedisi &Q) {
    Paket list[5] = {
        {"123456", "Hutao", 14, "Sumeru"},
        {"234567", "Ayaka", 10, "Fontaine"},
        {"345678", "Bennet", 7,  "Natlan"},
        {"456789", "Furina", 16, "Liyue"},
        {"567890", "Nefer",  6,  "Inazuma"}
    };

    cout << "\n--- Memasukkan 5 Paket ---\n";
    for (auto &p : list) enQueue(Q, p);
}

int main() {
    QueueEkspedisi Q;
    int pilih;

    createQueue(Q);
    cout << "Queue berhasil dibuat.\n";

    do {
        menu();
        cin >> pilih;

        switch (pilih) {
            case 1:
                createQueue(Q);
                cout << "Queue dibuat ulang.\n";
                break;

            case 2:
                inputSkenario(Q);
                viewQueue(Q);
                break;

            case 3:
                deQueue(Q);
                viewQueue(Q);
                break;

            case 4:
                viewQueue(Q);
                break;

            case 5:
                cout << "Total Biaya: Rp " 
                     << TotalBiayaPengiriman(Q) << "\n";
                break;

            case 0:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}
