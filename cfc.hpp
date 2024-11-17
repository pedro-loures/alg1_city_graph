#ifndef CFC_HPP
#define CFC_HPP

#include "grafo.hpp"
#include <vector>
#include <stack>

// Usa algorítmo de Tarjan para encontrar CFCs
std::vector<std::vector<int>> acharCFCs(const Grafo &grafo, std::vector<int> &CFC);

// Função que determina a capital com um CFC
int acharCapital(const Grafo &grafo);

#endif // CFC_HPP
