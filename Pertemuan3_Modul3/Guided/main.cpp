#include <iostream>
#include "Mahasiswa.h"
#include <cstdlib>
using namespace std;

int main(){
    Mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata rata nilai adalah : " << rata2 (mhs) << endl;
    system ("Pause");

    return 0;
}