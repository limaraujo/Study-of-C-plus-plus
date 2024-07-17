#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> mark;
    unordered_map<int, int> predecessores;
    int numEdge;
    int numNode;

public:
    Graph(int n) : numNode(n), numEdge(0), adjList(n), mark(n, UNVISITED) {}

    void setEdge(int i, int j) {
        adjList[i].push_back(j);
        adjList[j].push_back(i);  
        numEdge++;
    }

    void BFS(int v) {
        queue<int> Q;
        Q.push(v);
        mark[v] = VISITED;
        predecessores[v] = -1;

        while (!Q.empty()) {
            int s = Q.front();
            Q.pop();

            sort(adjList[s].begin(), adjList[s].end());  

            for (int w : adjList[s]) {
                if (mark[w] == UNVISITED) {
                    mark[w] = VISITED;
                    predecessores[w] = s;
                    Q.push(w);
                }
            }
        }
    }

    void graphTraverse(int start) {
        fill(mark.begin(), mark.end(), UNVISITED);
        predecessores.clear();
        BFS(start);
    }

    void menorCaminho(int inicio, int fim) {
        graphTraverse(inicio);
        vector<int> path;
        if (predecessores.find(fim) == predecessores.end()) {
            cout << -1 << endl;
            return;
        }

        for (int at = fim; at != -1; at = predecessores[at]) {
            path.push_back(at);
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            if (i != 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
};

int main() {
    int cases;
    cin >> cases;
    int v, a;
    int x, y, op;
    while(cases--){
        cout << "Caso " << cases+1 << endl;
        cin >> v >> a;
        Graph G(v);
        if(a>0){
            for (int j = 0; j < a; j++) {
                cin >> x >> y;
                G.setEdge(x, y);
            }
            cin >> op;
            while (op--) {
                cin >> x >> y;
                G.menorCaminho(x, y);
            }
        }
    }
    return 0;
}
