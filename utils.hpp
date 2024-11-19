#ifndef UTILS_HPP
#define UTILS_HPP

#include "grafo.hpp"
#include <queue>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

class IndexadorCidade {
private:
    std::unordered_map<std::string, int> cidadeParaIdx;
    std::unordered_map<int, std::string> idxParaCidade;
    int proxIdx;

public:
    IndexadorCidade();  // declaração do construtor
    int getAddCidade(const std::string& nomeCidade);
    std::string getCidade(int idx) const;
    int countCidades() const;
};

// Função principal para encontrar a capital
int acharCapital(const Grafo &grafo);

#endif