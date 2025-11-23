#include "Queue3.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    // Queue penuh jika (tail + 1) % MAX_QUEUE sama dengan head
    return (Q.tail + 1) % MAX_QUEUE == Q.head;
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "[ERROR] Circular Queue penuh! Tidak bisa enqueue " << x << endl;
        return;
    } 
    
    if (isEmpty(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        // Tail bergerak maju dan berputar
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "[ERROR] Circular Queue kosong!" << endl;
        return -1;
    }

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        // Jika hanya 1 elemen, buat queue kosong
        Q.head = Q.tail = -1;
    } else {
        // Head bergerak maju dan berputar
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " :  ";

    if (isEmpty(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        do {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
        } while (i != (Q.tail + 1) % MAX_QUEUE);
        
        cout << endl;
    }
}