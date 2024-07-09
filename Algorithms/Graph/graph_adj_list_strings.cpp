#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class Graph {
private:
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, int> mark;
    vector<string> nodes; 
    vector<string> topoSort;
    int numEdge;
    int numNode;

public:
    Graph(int n) : numEdge(0), numNode(0) {}

    string first(string i) {
        return adjList[i].empty() ? "" : adjList[i].front();
    }

    string next(string i, string j) {
        auto& neighbor = adjList[i];
        auto it = find(neighbor.begin(), neighbor.end(), j);
        if (it != neighbor.end() && (it + 1) != neighbor.end()) {
            return *(it + 1);
        }
        return "";
    }

    void setEdge(string i, string j) {
        adjList[i].push_back(j);
        nodes.push_back(i);
        nodes.push_back(j);
        numEdge++;
    }

    void delEdge(string i, string j) {
        auto& neighbors = adjList[i];
        auto it = find(neighbors.begin(), neighbors.end(), j);
        if (it != neighbors.end()) {
            neighbors.erase(it);
            numEdge--;
        }
    }

    bool isEdge(string i, string j) {
        return find(adjList[i].begin(), adjList[i].end(), j) != adjList[i].end();
    }

    void setMark(string v, int val) {
        mark[v] = val;
    }

    int getMark(string v) {
        return mark[v];
    }

    void printGraph() {
        cout << "Graph:" << endl;
        for (const auto& pair : adjList) {
            cout << pair.first << " -> ";
            const vector<string>& neighbors = pair.second;
            for (const string& neighbor : neighbors) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void DFS(string v) {
        mark[v] = VISITED;
        topoSort.push_back(v); // Adiciona o vértice à ordem topológica após visitar todos os vizinhos

        for (auto& node : adjList[v]) {
            if (mark[node] == UNVISITED)
                DFS(node);
        }
    }

    void BFS(string v) {
        queue<string> Q;
        Q.push(v);
        mark[v] = VISITED;

        while(!Q.empty()){
            string s = Q.front();
            Q.pop();
            cout << s << endl;

            for(string w : adjList[s]){
                if(mark[w] == UNVISITED){
                    mark[w] = VISITED;
                    Q.push(w);
                }
            }
        }
    }

    void graphTraverse() {
        for (auto& node : nodes) {
            mark[node] = UNVISITED;
        }

        for (auto& node : nodes) {
            if (mark[node] == UNVISITED) {
                DFS(node);
            }
        }
    }

    void testDFS() {
        cout << "Realizando DFS no grafo:" << endl;
        graphTraverse();

        cout << "Ordem topológica do grafo:" << endl;
        for (const auto& node : topoSort) {
            cout << node << " ";
        }
        cout << endl;
    }

    void testBFS() {
        cout << "Realizando BFS no grafo:" << endl;
        for (auto& node : nodes) {
            mark[node] = UNVISITED;
        }

        for (auto& node : nodes) {
            if (mark[node] == UNVISITED) {
                BFS(node);
            }
        }
    }
};

int main() {
    Graph g(0); // Criando um objeto da classe Graph

    // Adicionando arestas
    g.setEdge("A", "B");
    g.setEdge("A", "C");
    g.setEdge("B", "C");
    g.setEdge("C", "D");
    g.setEdge("E", "F");
    g.setEdge("H", "I");
    g.setEdge("M", "N");
    g.setEdge("Z", "X");

    g.printGraph();

    g.testDFS();

    // Testando first() e next()
    cout << "first(A): " << g.first("A") << endl;
    cout << "next(A, B): " << g.next("A", "B") << endl;
    cout << "next(A, C): " << g.next("A", "C") << endl;

    // Testando delEdge() e isEdge()
    g.delEdge("A", "C");
    cout << "Após remover A -> C:" << endl;
    cout << "first(A): " << g.first("A") << endl;
    cout << "isEdge(A, C): " << (g.isEdge("A", "C") ? "Sim" : "Não") << endl;

    // Testando setMark() e getMark()
    g.setMark("A", VISITED);
    g.setMark("B", UNVISITED);
    cout << "Mark de A: " << g.getMark("A") << endl;
    cout << "Mark de B: " << g.getMark("B") << endl;

    // Imprimindo o grafo atualizado
    g.printGraph();

    // Testando BFS
    g.testBFS();

    return 0;
}
