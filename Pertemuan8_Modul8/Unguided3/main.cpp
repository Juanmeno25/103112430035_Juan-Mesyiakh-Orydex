#include <iostream>
#include "Queue3.h" 

using namespace std;

int main() {
    cout << "--- Queue Alternatif 3 (Circular Queue (Berputar)) ---" << endl;
    cout << "H - T \t| Queue Info (MAX_SIZE = 5)" << endl;
    cout << "-----------------------------------" << endl;

    Queue Q;
    createQueue(Q);

    printInfo(Q); 
    enqueue(Q, 10); 
    enqueue(Q, 20); 
    enqueue(Q, 30); 
    enqueue(Q, 40); 
    printInfo(Q); 
    dequeue(Q); 
    dequeue(Q); 
    printInfo(Q); 
    enqueue(Q, 50); 
    enqueue(Q, 60);
    printInfo(Q); 
    enqueue(Q, 70); 
    dequeue(Q); 
    printInfo(Q); 
    enqueue(Q, 70); 
    printInfo(Q); 
    dequeue(Q); 
    dequeue(Q); 
    dequeue(Q); 
    dequeue(Q); 
    printInfo(Q); 
    
    return 0;
}