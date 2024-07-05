#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> mark;
    vector<int> nodes; 
    vector<int> topoSort;
    int numEdge;
    int numNode;

public:
    Graph(int n) : numNode(n), numEdge(0), adjList(n), mark(n, UNVISITED) {
        for (int i = 0; i < n; ++i) {
            nodes.push_back(i);
        }
    }

    int first(int i) {
        return adjList[i].empty() ? -1 : adjList[i].front();
    }

    int next(int i, int j) {
        auto& neighbor = adjList[i];
        auto it = find(neighbor.begin(), neighbor.end(), j);
        if (it != neighbor.end() && (it + 1) != neighbor.end()) {
            return *(it + 1);
        }
        return -1;
    }

    void setEdge(int i, int j) {
        adjList[i].push_back(j);
        numEdge++;
    }

    void delEdge(int i, int j) {
        auto& neighbors = adjList[i];
        auto it = find(neighbors.begin(), neighbors.end(), j);
        if (it != neighbors.end()) {
            neighbors.erase(it);
            numEdge--;
        }
    }

    bool isEdge(int i, int j) {
        return find(adjList[i].begin(), adjList[i].end(), j) != adjList[i].end();
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) {
        return mark[v];
    }

    void printGraph() {
        cout << "Graph:" << endl;
        for (int i = 0; i < numNode; ++i) {
            cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void DFS(int v) {
        mark[v] = VISITED;
        topoSort.push_back(v); // Adiciona o vértice à ordem topológica após visitar todos os vizinhos

        for (int node : adjList[v]) {
            if (mark[node] == UNVISITED)
                DFS(node);
        }
    }

    void BFS(int v) {
        queue<int> Q;
        Q.push(v);
        mark[v] = VISITED;

        while(!Q.empty()){
            int s = Q.front();
            Q.pop();
            cout << s << " ";

            for (int w : adjList[s]) {
                if (mark[w] == UNVISITED) {
                    mark[w] = VISITED;
                    Q.push(w);
                }
            }
        }
    }

    void graphTraverse() {
        fill(mark.begin(), mark.end(), UNVISITED);

        for (int node : nodes) {
            if (mark[node] == UNVISITED) {
                DFS(node);
            }
        }
    }

    void testDFS() {
        cout << "Realizando DFS no grafo:" << endl;
        graphTraverse();

        cout << "Ordem topológica do grafo:" << endl;
        for (int node : topoSort) {
            cout << node << " ";
        }
        cout << endl;
    }

    void testBFS() {
        cout << "Realizando BFS no grafo:" << endl;
        fill(mark.begin(), mark.end(), UNVISITED);

        for (int node : nodes) {
            if (mark[node] == UNVISITED) {
                BFS(node);
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(10); // Criando um objeto da classe Graph com 10 nós

    // Adicionando arestas
    g.setEdge(0, 1); // A -> B
    g.setEdge(0, 2); // A -> C
    g.setEdge(1, 2); // B -> C
    g.setEdge(2, 3); // C -> D
    g.setEdge(4, 5); // E -> F
    g.setEdge(7, 8); // H -> I
    g.setEdge(9, 6); // Z -> X
    g.setEdge(6, 7); // X -> H

    g.printGraph();

    g.testDFS();

    // Testando first() e next()
    cout << "first(0): " << g.first(0) << endl;
    cout << "next(0, 1): " << g.next(0, 1) << endl;
    cout << "next(0, 2): " << g.next(0, 2) << endl;

    // Testando delEdge() e isEdge()
    g.delEdge(0, 2);
    cout << "Após remover 0 -> 2:" << endl;
    cout << "first(0): " << g.first(0) << endl;
    cout << "isEdge(0, 2): " << (g.isEdge(0, 2) ? "Sim" : "Não") << endl;

    // Testando setMark() e getMark()
    g.setMark(0, VISITED);
    g.setMark(1, UNVISITED);
    cout << "Mark de 0: " << g.getMark(0) << endl;
    cout << "Mark de 1: " << g.getMark(1) << endl;

    // Imprimindo o grafo atualizado
    g.printGraph();

    // Testando BFS
    g.testBFS();

    return 0;
}
