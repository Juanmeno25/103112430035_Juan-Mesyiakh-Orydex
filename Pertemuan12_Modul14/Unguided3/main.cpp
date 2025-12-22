#include "graph3.h"
int main() {
    Graph G; CreateGraph(G);
    InsertNode(G, 'A'); 
    InsertNode(G, 'B'); 
    InsertNode(G, 'C'); 
    InsertNode(G, 'D');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'D'));
    cout << "Hasil Penelusuran BFS: ";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));
    return 0;
}