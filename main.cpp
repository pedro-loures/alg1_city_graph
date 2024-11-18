/*
src/
│
├── main.cpp                // main do programa
├── grafo.hpp               // Header da classe grafos
├── grafo.cpp               // Implementação da classe grafos
├── cfc.hpp                 // Header da computação dos Componentes Fortementes Conexos
├── cfc.cpp                 // Implementation da computação dos Componentes Fortemente Conexos
├── utils.hpp               // Header para funções de utilidades
└── utils.cpp               // Implementação das funções de utilidades
*/


#include "grafo.hpp"
#include "scc.hpp"
#include <iostream>
#include <vector>


int main() {

    int numCentros, numArestas;
    std::cin >> numCentros >> numArestas;

    Grafo grafo(numCentros);

    for (int i = 0; i < numArestas; ++i) {
        int de, para;
        std::cin >> de >> para;
        grafo.adicionarAresta(de, para);
    }

    // *********** Definindo a capital *********
    int capital = acharCapital(grafo);
    if (capital == -1) {
        std::cerr << "Erro: Mais de um CFC com grau de entrada zero." << std::endl;
        return 1; // retorno de erro
    }

    # Retornar capital
    std::cout << "Capital: " << capital << endl;

    // *********** /Definindo a capital ********
    // *********** Batalhões *******************

    // *********** /Batalhões ******************
    // *********** patrulhamentos **************

    // *********** /patrulhamentos *************


    return 0;
}