#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<int> mark;
    int numEdges, numNodes;
    bool isConect;

public:
    Graph(int N) : numEdges(0), numNodes(N), adjList(N), mark(N, UNVISITED), isConect(true) {}

    void setEdge(int i, int j, int wt) {
        adjList[i].emplace_back(j, wt);
        adjList[j].emplace_back(i, wt); // Grafo não direcionado
        numEdges++;
    }

    void Prim(int D[], int P[]) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        int p, v;

        for (int i = 0; i < numNodes; i++) {
            D[i] = INF; 
            P[i] = -1; 
            mark[i] = UNVISITED;
        }

        H.push({0, {0, 0}}); 
        D[0] = 0;

        for (int i = 0; i < numNodes; i++) {
            do {
                if (H.empty()) { 
                    isConect = false; 
                    return; 
                }
                auto top = H.top(); 
                H.pop();
                p = top.second.first;
                v = top.second.second;
            } while (mark[v] == VISITED);

            mark[v] = VISITED; P[v] = p;

            for (auto neighbor : adjList[v]) {
                int w = neighbor.first;
                int weight = neighbor.second;
                if (mark[w] != VISITED && D[w] > weight) {
                    D[w] = weight;
                    H.push({weight, {v, w}});
                }
            }
        }
    }

    bool isConnected() const {
        return isConect;
    }
};

int main() {
    Graph G(5);

    G.setEdge(0, 1, 10);
    G.setEdge(0, 2, 3);
    G.setEdge(0, 3, 20);
    G.setEdge(1, 3, 5);
    G.setEdge(2, 1, 2);
    G.setEdge(2, 4, 15);
    G.setEdge(3, 4, 11);

    int D[5], P[5];
    G.Prim(D, P);

    if (G.isConnected()) {
        for (int i = 0; i < 5; i++) {
            cout << "Node: " << i << " Parent: " << P[i] << " Distance: " << D[i] << endl;
        }
    } else {
        cout << "The graph is not connected!" << endl;
    }

    return 0;
}
