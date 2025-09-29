#include <iostream>
using namespace std;

int main(){
    float P1, P2, Jarak;
    
    cout <<"Masukan nilai waktu: ";
    cin >> P1;
    cout <<"Masukan nilai waktu: ";
    cin >> P2;

    Jarak = P1 - P2;
    cout << "Selisih dari waktu tersebut: "<< Jarak<< endl;
    return 0;
}