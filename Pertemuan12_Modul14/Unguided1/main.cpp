#include "graph1.h"
int main() {
    Graph G;
    CreateGraph(G);
    InsertNode(G, 'A'); 
    InsertNode(G, 'B'); 
    InsertNode(G, 'C');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    cout << "Struktur Graph Soal 1:" << endl;
    PrintInfoGraph(G);
    return 0;
}