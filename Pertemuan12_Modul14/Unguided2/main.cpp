#include "graph2.h"
int main() {
    Graph G; 
    CreateGraph(G);
    InsertNode(G, 'A'); 
    InsertNode(G, 'B'); 
    InsertNode(G, 'C'); 
    InsertNode(G, 'D');
    ConnectNode(FindNode(G, 'A'), FindNode(G, 'B'));
    ConnectNode(FindNode(G, 'B'), FindNode(G, 'C'));
    ConnectNode(FindNode(G, 'C'), FindNode(G, 'D'));
    cout << "Hasil Penelusuran DFS: ";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));
    return 0;
}