#include <iostream>
#include <string>

using namespace std;

struct Edge {
    char tujuan;
    Edge* nextEdge;
};

struct NodeKota {
    char namaKota;
    bool isLockdown;
    bool isVisited;
    Edge* firstEdge;
    NodeKota* nextNode;
};

struct Graph {
    NodeKota* firstNode;
};

void initGraph(Graph &G) {
    G.firstNode = NULL;
}

NodeKota* alokasiNode(char nama) {
    NodeKota* P = new NodeKota;
    P->namaKota = nama;
    P->isLockdown = false;
    P->isVisited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, char nama) {
    NodeKota* P = alokasiNode(nama);
    if (G.firstNode == NULL) {
        G.firstNode = P;
    } else {
        NodeKota* temp = G.firstNode;
        while (temp->nextNode != NULL) {
            temp = temp->nextNode;
        }
        temp->nextNode = P;
    }
}

NodeKota* findNode(Graph G, char nama) {
    NodeKota* temp = G.firstNode;
    while (temp != NULL) {
        if (temp->namaKota == nama) return temp;
        temp = temp->nextNode;
    }
    return NULL;
}

void addEdge(Graph &G, char asal, char tujuan) {
    NodeKota* P = findNode(G, asal);
    if (P != NULL) {
        Edge* E = new Edge;
        E->tujuan = tujuan;
        E->nextEdge = P->firstEdge;
        P->firstEdge = E;
    }
}

void hubungkan(Graph &G, char a, char b) {
    addEdge(G, a, b);
    addEdge(G, b, a);
}

void resetStatus(Graph &G) {
    NodeKota* temp = G.firstNode;
    while (temp != NULL) {
        temp->isVisited = false;
        temp = temp->nextNode;
    }
}

void traversalDFS(Graph &G, NodeKota* curr) {
    if (curr == NULL || curr->isVisited || curr->isLockdown) return;
    curr->isVisited = true;
    Edge* E = curr->firstEdge;
    while (E != NULL) {
        NodeKota* tetangga = findNode(G, E->tujuan);
        traversalDFS(G, tetangga);
        E = E->nextEdge;
    }
}

void tampilkanJaringan(Graph G) {
    cout << "Membangun Jaringan Distribusi Vaksin" << endl;
    NodeKota* P = G.firstNode;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        Edge* E = P->firstEdge;
        while (E != NULL) {
            cout << E->tujuan << " ";
            E = E->nextEdge;
        }
        cout << endl;
        P = P->nextNode;
    }
}

void analisisKotaKritis(Graph &G) {
    cout << "\nAnalisis Kota Kritis (Single Point of Failure)" << endl;
    NodeKota* uji = G.firstNode;
    while (uji != NULL) {
        resetStatus(G);
        uji->isLockdown = true;
        NodeKota* start = G.firstNode;
        if (start == uji) start = start->nextNode;
        if (start != NULL) traversalDFS(G, start);
        bool terputus = false;
        NodeKota* cek = G.firstNode;
        while (cek != NULL) {
            if (!cek->isLockdown && !cek->isVisited) {
                terputus = true;
                break;
            }
            cek = cek->nextNode;
        }
        if (terputus) {
            cout << "[PERINGATAN] Kota " << uji->namaKota << " adalah KOTA KRITIS!" << endl;
            cout << "-> Jika " << uji->namaKota << " lockdown, distribusi terputus." << endl;
        } else {
            cout << "Kota " << uji->namaKota << " aman (redundansi oke)." << endl;
        }
        uji->isLockdown = false;
        uji = uji->nextNode;
    }
}

int main() {
    Graph G;
    initGraph(G);
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    hubungkan(G, 'A', 'B');
    hubungkan(G, 'B', 'E');
    hubungkan(G, 'B', 'C');
    hubungkan(G, 'C', 'D');
    tampilkanJaringan(G);
    analisisKotaKritis(G);
    return 0;
}
