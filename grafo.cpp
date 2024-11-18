#include "grafo.hpp"

Grafo::Grafo(int n) : numNodos(n), adj(n), revAdj(n) {}

void Grafo::adicionarAresta(int de, int para) {
    adj[de].push_back(para);
    revAdj[para].push_back(de);
}
