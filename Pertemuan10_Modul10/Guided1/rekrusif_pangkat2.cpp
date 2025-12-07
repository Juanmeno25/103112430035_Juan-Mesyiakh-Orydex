#include <iostream>
using namespace std;

int pangkat_2(int x) {
    // Basis
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x - 1);
    }
}
int main() {
    cout << "=====REKRUSIF PANGKAT 2=====" << endl;
    int x;
    cout << "Masukkax xilai x: ";
    cin >> x;
    cout << "2 pangkat " << x << " adalah " << pangkat_2(x) << endl;
    return 0;
}