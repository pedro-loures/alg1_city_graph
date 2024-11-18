#include "utils.hpp"
#include <queue>
#include <vector>
#include <climits>

int acharCapital(const Grafo &grafo) {
    int melhorCapital = -1;
    int menorMaxDistancia = INT_MAX;
    
    // Para cada possível capital
    for (int candidato = 0; candidato < grafo.numNodos; candidato++) {
        // Faz BFS a partir do candidato
        std::vector<int> distancias(grafo.numNodos, -1);
        int maxDistancia = 0;
        bool alcancaTodos = true;
        
        std::queue<int> fila;
        fila.push(candidato);
        distancias[candidato] = 0;
        
        while (!fila.empty()) {
            int atual = fila.front();
            fila.pop();
            
            for (int vizinho : grafo.adj[atual]) {
                if (distancias[vizinho] == -1) {
                    distancias[vizinho] = distancias[atual] + 1;
                    maxDistancia = std::max(maxDistancia, distancias[vizinho]);
                    fila.push(vizinho);
                }
            }
        }
        
        // Verifica se alcança todos os nós
        for (int i = 0; i < grafo.numNodos; i++) {
            if (distancias[i] == -1) {
                alcancaTodos = false;
                break;
            }
        }
        
        // Atualiza melhor capital se necessário
        if (alcancaTodos && maxDistancia < menorMaxDistancia) {
            menorMaxDistancia = maxDistancia;
            melhorCapital = candidato;
        }
    }
    
    return melhorCapital;
}