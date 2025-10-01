#include <iostream>
using namespace std;

int main (){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukan value index ke-" << i << " : ";
    }
    int j = 0;
    while (j < 5){
       cout << "isi index ke-" << j << " : " << arr[j] << endl;
       j++;
    }
    return 0;

}
