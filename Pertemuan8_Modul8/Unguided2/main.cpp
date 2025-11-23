#include <iostream>
#include "Queue2.h" 

using namespace std;

int main() {
    cout << "--- Queue Alternatif 2 (Head & Tail Bergerak) ---" << endl;
    
    cout << "H - T " << " : " << "Queue Info (MAX_SIZE = 5)" << endl;
    cout << "-----------------------------------" << endl;

    Queue Q;
    createQueue(Q);
    printInfo(Q); 
    enqueue(Q, 10); 
    printInfo(Q); 
    enqueue(Q, 20); 
    printInfo(Q); 
    enqueue(Q, 30); 
    printInfo(Q);
    int val1 = dequeue(Q); 
    cout << "Dequeued: " << val1 << endl;
    printInfo(Q);
    int val2 = dequeue(Q);
    cout << "Dequeued: " << val2 << endl; 
    printInfo(Q); 
    enqueue(Q, 40); 
    printInfo(Q);
    enqueue(Q, 50); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q); 
    dequeue(Q); 
    printInfo(Q);
    dequeue(Q); 
    printInfo(Q);
    return 0;
}