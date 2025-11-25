#include "Mahasiswa.h"

int main() {
    StackMahasiswa MHS_Stack;
    
    cout << " 1) Membuat Stack Kosong " << endl;
    createStack(MHS_Stack);
    cout << endl;

    Mahasiswa dataMHS[] = {
        {"Venti", "11111", 75.7, 82.1, 65.5},
        {"Xiao", "22222", 87.4, 88.9, 81.9},
        {"Kazuha", "33333", 92.3, 88.8, 82.4},
        {"Wanderer", "44444", 95.5, 85.5, 90.5},
        {"Lynette", "55555", 77.7, 65.4, 79.9},
        {"Chasca", "66666", 99.9, 93.6, 87.3}
    };

    cout << " 2) Input Data Mahasiswa (Push) " << endl;
    for (int i = 0; i < 6; i++) {
        Push(MHS_Stack, dataMHS[i]);
    }
    cout << endl;

    cout << " 3) Tampilkan Stack Awal " << endl;
    View(MHS_Stack);
    
    cout << "\n 4) Melakukan Pop 1x " << endl;
    Mahasiswa poppedData = Pop(MHS_Stack);
    cout << endl;

    cout << " 5) Tampilkan Stack Setelah Pop " << endl;
    View(MHS_Stack);

    Mahasiswa dataHeizou = {"Heizou", "77777", 99.9, 88.8, 77.7};
    int posisiUpdate = 3;
    
    cout << "\n 6) Melakukan Update Data pada Posisi ke-" << posisiUpdate << " " << endl;
    Update(MHS_Stack, posisiUpdate, dataHeizou);
    cout << endl;

    cout << " 7) Tampilkan Stack Setelah Update " << endl;
    View(MHS_Stack);

    float minSearch = 85.5;
    float maxSearch = 95.5;
    cout << "\n 8) Searching Data (NilaiAkhir " << fixed << setprecision(1) << minSearch << " - " << maxSearch << ") " << endl;
    SearchNilaiAkhir(MHS_Stack, minSearch, maxSearch);

    cout << "\n Bagian B: Pencarian Nilai Akhir Terbesar " << endl;
    ProsedurMaxNilaiAkhir(MHS_Stack);

    return 0;
}