#include "Mahasiswa.h"

float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (0.20 * tugas) + (0.40 * uts) + (0.40 * uas);
}

bool isEmpty(StackMahasiswa& StackMHS) {
    return StackMHS.Top == -1;
}

bool isFull(StackMahasiswa& StackMHS) {
    return StackMHS.Top == MAX - 1;
}

void createStack(StackMahasiswa& StackMHS) {
    StackMHS.Top = -1;
    cout << "Stack Mahasiswa berhasil dibuat (kosong)." << endl;
}

void Push(StackMahasiswa& StackMHS, Mahasiswa data) {
    if (isFull(StackMHS)) {
        cout << "Gagal Push: Stack penuh!" << endl;
    } else {
        StackMHS.Top++;
        data.NilaiAkhir = hitungNilaiAkhir(data.NilaiTugas, data.NilaiUTS, data.NilaiUAS);
        StackMHS.dataMahasiswa[StackMHS.Top] = data;
        cout << "Data Mahasiswa **" << data.Nama << "** berhasil di-Push pada posisi ke-" << StackMHS.Top + 1 << endl;
    }
}

Mahasiswa Pop(StackMahasiswa& StackMHS) {
    Mahasiswa dummy = {"", "", 0.0, 0.0, 0.0, 0.0};
    if (isEmpty(StackMHS)) {
        cout << "Gagal Pop: Stack kosong!" << endl;
        return dummy;
    } else {
        Mahasiswa poppedData = StackMHS.dataMahasiswa[StackMHS.Top];
        StackMHS.Top--;
        cout << "Data Mahasiswa **" << poppedData.Nama << "** berhasil di-Pop." << endl;
        return poppedData;
    }
}

void Update(StackMahasiswa& StackMHS, int posisi, Mahasiswa dataUpdate) {
    int index = posisi - 1;

    if (index < 0 || index > StackMHS.Top) {
        cout << "Gagal Update: Posisi ke-" << posisi << " tidak valid!" << endl;
        return;
    }

    dataUpdate.NilaiAkhir = hitungNilaiAkhir(dataUpdate.NilaiTugas, dataUpdate.NilaiUTS, dataUpdate.NilaiUAS);
    StackMHS.dataMahasiswa[index] = dataUpdate;
    cout << "Data Mahasiswa pada posisi ke-" << posisi << " berhasil di-Update menjadi **" << dataUpdate.Nama << "**." << endl;
}

void View(StackMahasiswa& StackMHS) {
    cout << "\n--- **Tampilan Isi Stack Mahasiswa** ---" << endl;
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong, tidak ada data untuk ditampilkan." << endl;
        return;
    }

    cout << left << setw(5) << "No"
         << setw(15) << "Nama"
         << setw(10) << "NIM"
         << setw(8) << "Tugas"
         << setw(8) << "UTS"
         << setw(8) << "UAS"
         << setw(10) << "Akhir"
         << endl;

    for (int i = 0; i <= StackMHS.Top; i++) {
        cout << left << setw(5) << i + 1
             << setw(15) << StackMHS.dataMahasiswa[i].Nama
             << setw(10) << StackMHS.dataMahasiswa[i].NIM
             << fixed << setprecision(1)
             << setw(8) << StackMHS.dataMahasiswa[i].NilaiTugas
             << setw(8) << StackMHS.dataMahasiswa[i].NilaiUTS
             << setw(8) << StackMHS.dataMahasiswa[i].NilaiUAS
             << setw(10) << StackMHS.dataMahasiswa[i].NilaiAkhir;

        if (i == StackMHS.Top) {
            cout << " <- TOP";
        }
        cout << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa& StackMHS, float NilaiAkhirMin, float NilaiAkhirMax) {
    cout << "\n--- **Hasil Searching (NilaiAkhir " << fixed << setprecision(1) << NilaiAkhirMin << " - " << NilaiAkhirMax << ")** ---" << endl;
    bool found = false;
    
    for (int i = 0; i <= StackMHS.Top; i++) {
        float nilaiAkhir = StackMHS.dataMahasiswa[i].NilaiAkhir;
        
        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Ditemukan pada Posisi ke-" << i + 1 << ":" << endl;
            cout << "  Nama: " << StackMHS.dataMahasiswa[i].Nama << endl;
            cout << "  NIM: " << StackMHS.dataMahasiswa[i].NIM << endl;
            cout << "  Nilai Akhir: " << fixed << setprecision(2) << nilaiAkhir << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada data mahasiswa dengan Nilai Akhir dalam rentang tersebut." << endl;
    }

}

void ProsedurMaxNilaiAkhir(StackMahasiswa& StackMHS) {
    cout << "\n--- **Data Mahasiswa dengan NilaiAkhir Terbesar** ---" << endl;
    if (isEmpty(StackMHS)) {
        cout << "Stack kosong, tidak dapat mencari nilai maksimum." << endl;
        return;
    }

    float maxNilai = -1.0;
    int maxIndex = -1;

    for (int i = 0; i <= StackMHS.Top; i++) {
        if (StackMHS.dataMahasiswa[i].NilaiAkhir > maxNilai) {
            maxNilai = StackMHS.dataMahasiswa[i].NilaiAkhir;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        cout << "Nilai Akhir Terbesar: " << fixed << setprecision(2) << StackMHS.dataMahasiswa[maxIndex].NilaiAkhir << endl;
        cout << "Data Mahasiswa (Posisi ke-" << maxIndex + 1 << "):" << endl;
        cout << "  Nama: " << StackMHS.dataMahasiswa[maxIndex].Nama << endl;
        cout << "  NIM: " << StackMHS.dataMahasiswa[maxIndex].NIM << endl;
        cout << "  Nilai Tugas: " << fixed << setprecision(1) << StackMHS.dataMahasiswa[maxIndex].NilaiTugas << endl;
        cout << "  Nilai UTS: " << StackMHS.dataMahasiswa[maxIndex].NilaiUTS << endl;
        cout << "  Nilai UAS: " << StackMHS.dataMahasiswa[maxIndex].NilaiUAS << endl;
    }
}