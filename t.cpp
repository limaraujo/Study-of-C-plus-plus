#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define UNVISITED 0
#define VISITED 1

class Graph{
private:
    vector<vector<pair<int,int>>> adjList;
    vector<int> mark;
    int numEdges, numNodes;

public:
    Graph(int N) : adjList(N), mark(N, UNVISITED), numNodes(N), numEdges(0){}

    void setEdge(int i, int j, int wt){
        adjList[i].emplace_back(j,wt);
        adjList[j].emplace_back(i,wt);
        numEdges++;
    }

    void Dijkstra(int s, int D[]){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        int P[numNodes]; int v, p;

        for(int i = 0; i < numNodes; i++){
            D[i] = INF; P[i] = -1; mark[i] = UNVISITED;
        }

        H.push({0,{s,0}}); D[s] = 0;
        for(int i = 0; i < numNodes; i++){
        do{
            if(H.empty()) return;
            auto top = H.top(); H.pop();
            p = top.second.first;
            v = top.second.second;
        }while(mark[v] == VISITED);

        mark[v] = VISITED; P[v] = p;
        for(auto neighbor : adjList[v]){
            int w = neighbor.first;
            int weight = neighbor.second;
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
    g.Dijkstra(0, D); // Executa o algoritmo de Dijkstra a partir do nó de origem 0

    // Exibe as distâncias do nó de origem (0) para todos os outros nós
    for (int i = 0; i < numNodes; i++) {
        cout << "Distância do nó 0 ao nó " << i << " é " << D[i] << endl;
    }

    return 0;
}
