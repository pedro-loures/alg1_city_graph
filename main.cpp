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
#include "cfc.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>


int main() {


    std::cout<<"Hello World"<<std::endl;

    int numCentros, numArestas;
    std::cin >> numCentros >> numArestas;

    Grafo grafo(numCentros);
    IndexadorCidade indexador;

    // std::cout << "criou grafo" << std::endl;
    int de = -1, para = -1;
    std::string cidadeA ="", cidadeB = "";
    for (int i = 0; i < numArestas; ++i) {

        std::cin >> cidadeA >> cidadeB;
        de = indexador.getAddCidade(cidadeA);
        para = indexador.getAddCidade(cidadeB);
        std::cout << de << " " << para << std::endl;
        if (de == para){
            std::cerr << "Erro: Aresta de um nodo para ele mesmo." << std::endl;
            return -1;
        }
        grafo.adicionarAresta(de, para);
    }

    // std::cout << "adicionou arestas" << std::endl;
    // *********** Definindo a capital *********
    int capital = acharCapital(grafo);
    // std::cout << "achou capital" << std::endl;
    if (capital == -1) {
        std::cerr << "Erro: Mais de um CFC com grau de entrada zero." << std::endl;
        return 1; // retorno de erro
    }

    // Retornar capital
    std::cout << "Capital: " << indexador.getCidade(capital) << std::endl;

    // *********** /Definindo a capital ********
    // *********** Batalhões *******************

    // *********** /Batalhões ******************
    // *********** patrulhamentos **************

    // *********** /patrulhamentos *************


    return 0;
}