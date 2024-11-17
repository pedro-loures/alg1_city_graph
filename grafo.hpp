#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <unordered_set>

class Grafo {
public:
    int numCentros;
    std::vector<std::vector<int>> adj;     // Lista de adjacência
    std::vector<std::vector<int>> revAdj;  // Lista de adjacência reversa (para cálculo de CFC)

    Grafo(int n);
    void adicionarAresta(int de, int para);
};

#endif // GRAFO_HPP
