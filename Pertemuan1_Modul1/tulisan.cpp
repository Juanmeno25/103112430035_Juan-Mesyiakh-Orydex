#include <iostream>
using namespace std;

string angkatulisan(int n) {
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };

    string puluhan[] = {
        "", "", "dua puluh ", "tiga puluh ",
        "empat puluh ", "lima puluh ", "enam puluh ",
        "tujuh puluh ", "delapan puluh ", "sembilan puluh "
    };

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        int puluh = n / 10;
        int sisanya = n % 10;
        if (sisanya == 0) {
            return puluhan[puluh];
        } else {
            return puluhan[puluh] + satuan[sisanya];
        }
    } else if (n == 100) {
        return "seratus";
    }

    return "Bukan angka yang diinginkan (hanya 1 - 100)";
}

int main() {
    int angka;
    cout << "Masukkan angka dari 1 sampai 100 : ";
    cin >> angka;
    cout << "Keluarnya : " << angkatulisan(angka) << endl;
    return 0;
}
