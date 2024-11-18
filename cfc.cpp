#include "cfc.hpp"
#include <stack>
#include <unordered_set>
#include <vector>

void tarjanDFS(int nodo, int &tempo, std::vector<int> &tDesc, std::vector<int> &menorT,
               std::stack<int> &pilhaDFS, std::vector<bool> &inPilha, const Grafo &grafo,
               std::vector<int> &cfc, std::vector<std::vector<int>> &listaCfc) {
    
    tDesc[nodo] = menorT[nodo] = tempo++;
    pilhaDFS.push(nodo);
    inPilha[nodo] = true;

    // Roda DFS para os vizinhos
    for (int vizinho : grafo.adj[nodo]) {
        if (tDesc[vizinho] == -1) {
            tarjanDFS(vizinho, tempo, tDesc, menorT, pilhaDFS, inPilha, grafo, cfc, listaCfc);
            menorT[nodo] = (menorT[nodo] < menorT[vizinho]) ? menorT[nodo] : menorT[vizinho];
        } else if (inPilha[vizinho]) {
            menorT[nodo] = (menorT[nodo] < tDesc[vizinho]) ? menorT[nodo] : tDesc[vizinho];
        }
    }

    // Processa componente fortemente conexo do nodo
    if (menorT[nodo] == tDesc[nodo]) {
        std::vector<int> currentCFC;
        int poped_nodo;
        do {
            poped_nodo = pilhaDFS.top();
            pilhaDFS.pop();
            inPilha[poped_nodo] = false;
            currentCFC.push_back(poped_nodo);
            cfc[poped_nodo] = listaCfc.size();
        } while (poped_nodo != nodo);
        listaCfc.push_back(currentCFC);
    }
}

// Usa algorítmo de Tarjan para encontrar CFCs
std::vector<std::vector<int>> acharCFCs(const Grafo &grafo, std::vector<int> &cfc) {
    int tempo = 0;
    std::vector<int> tDesc(grafo.numNodos, -1), menorT(grafo.numNodos, -1);
    std::stack<int> pilhaDFS;
    std::vector<bool> inPilha(grafo.numNodos, false);
    std::vector<std::vector<int>> listaCfc;

    for (int i = 0; i < grafo.numNodos; ++i) {
        if (tDesc[i] == -1) {
            tarjanDFS(i, tempo, tDesc, menorT, pilhaDFS, inPilha, grafo, cfc, listaCfc);
        }
    }
    return listaCfc;
}

// Função que determina a capital com um CFC
int acharCapital(const Grafo &grafo) {
    std::vector<int> cfc(grafo.numNodos, -1);
    std::vector<std::vector<int>> listaCfc = acharCFCs(grafo, cfc);

    // Cria um grafo condensado
    std::vector<std::unordered_set<int>> grafoCondensado(listaCfc.size());
    std::vector<int> inDegree(listaCfc.size(), 0);

    for (int i = 0; i < grafo.numNodos; ++i) {
        for (int vizinho : grafo.adj[i]) {
            if (cfc[i] != cfc[vizinho]) {
                if (grafoCondensado[cfc[i]].insert(cfc[vizinho]).second) {
                    inDegree[cfc[vizinho]]++;
                }
            }
        }
    }

    // Encontar CFC com in-degree zero
    int cfcCandidato = -1;
    for (int i = 0; i < listaCfc.size(); ++i) {
        if (inDegree[i] == 0) {
            if (cfcCandidato != -1) {
                return -1; // Mais de um CFC com in-degree zero
            }
            cfcCandidato = i;
        }
    }

    if (cfcCandidato == -1) {
        return -1; // Nem um CFC com in-degree zero
    }

    // Retorna um nodo do CFC com in-degree zero que tem vizinhos fora do CFC
    for (int nodo : listaCfc[cfcCandidato]) {
        for (int vizinho : grafo.adj[nodo]) {
            if (cfc[vizinho] != cfcCandidato) {
                return nodo;
            }
        }
    }

    // Caso não tenha encontrado, retorna qualquer nodo do CFC
    return listaCfc[cfcCandidato][0];
}