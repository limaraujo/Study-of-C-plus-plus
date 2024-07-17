#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000 // Define uma constante para representar infinito (um valor muito grande)
#define UNVISITED 0    // Define uma constante para representar um nó não visitado
#define VISITED 1      // Define uma constante para representar um nó visitado

struct element {
    int parent, distance; // Estrutura para armazenar o pai e a distância de um nó
    element(int p, int d) : parent(p), distance(d) {} // Construtor para inicializar os valores
};

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> adjList; // Lista de adjacência para armazenar as arestas e seus pesos
    unordered_map<int, int> mark; // Marca para verificar se um nó foi visitado
    int numEdges, numNodes; // Número de arestas e nós no grafo

    int n() { return numNodes; } // Retorna o número de nós
    int e() { return numEdges; } // Retorna o número de arestas

public:
    Graph(int N) : numEdges(0), numNodes(N) { // Construtor para inicializar o grafo com N nós
        for (int i = 0; i < N; i++) {
            adjList[i]; // Inicializa a lista de adjacência para cada nó
            mark[i] = UNVISITED; // Marca todos os nós como não visitados
        }
    }

    void setEdge(int i, int j, int wt) { // Adiciona uma aresta entre os nós i e j com peso wt
        adjList[i].emplace_back(j, wt);
        numEdges++;
    }

    void dijkstra(int s, int D[]) { // Implementação do algoritmo de Dijkstra
        // Fila de prioridade mínima para armazenar as distâncias
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        int P[numNodes]; // Array para armazenar os pais dos nós
        fill(P, P + numNodes, -1); // Inicializa o array P com -1
        int p, v;

        for (int i = 0; i < numNodes; i++) {
            D[i] = INF; // Inicializa todas as distâncias como infinito
            mark[i] = UNVISITED; // Marca todos os nós como não visitados
        }

        H.push({0, {s, 0}}); // Insere o nó de origem s na fila com distância 0
        D[s] = 0; // A distância do nó de origem para ele mesmo é 0

        for (int i = 0; i < numNodes; i++) {
            do {
                if (H.empty()) return; // Se a fila estiver vazia, termina a execução
                auto top = H.top(); H.pop(); // Remove o elemento com menor distância da fila
                p = top.second.first;
                v = top.second.second;
            } while (mark[v] == VISITED); // Repete até encontrar um nó não visitado

            mark[v] = VISITED; // Marca o nó atual como visitado
            P[v] = p; // Define o pai do nó atual

            for (auto& neighbor : adjList[v]) { // Percorre todos os vizinhos do nó atual
                int w = neighbor.first; // Nó vizinho
                int weight = neighbor.second; // Peso da aresta
                if (mark[w] != VISITED && D[w] > D[v] + weight) { // Se o vizinho não foi visitado e a nova distância é menor
                    D[w] = D[v] + weight; // Atualiza a distância do vizinho
                    H.push({D[w], {v, w}}); // Insere o vizinho na fila de prioridade com a nova distância
                }
            }
        }
    }
};

int main() {
    int numNodes = 5; // Define o número de nós no grafo
    Graph g(numNodes); // Cria um grafo com 5 nós

    // Adiciona as arestas com seus respectivos pesos
    g.setEdge(0, 1, 10);
    g.setEdge(0, 3, 30);
    g.setEdge(0, 4, 100);
    g.setEdge(1, 2, 50);
    g.setEdge(2, 4, 10);
    g.setEdge(3, 2, 20);
    g.setEdge(3, 4, 60);

    int D[numNodes]; // Array para armazenar as distâncias
    g.dijkstra(0, D); // Executa o algoritmo de Dijkstra a partir do nó de origem 0

    // Exibe as distâncias do nó de origem (0) para todos os outros nós
    for (int i = 0; i < numNodes; i++) {
        cout << "Distância do nó 0 ao nó " << i << " é " << D[i] << endl;
    }

    return 0;
}
