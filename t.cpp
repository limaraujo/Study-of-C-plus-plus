#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define UNVISITED 0
#define VISITED 1

struct element {
    int parent, distance;
    element(int p, int d) : parent(p), distance(d) {}
};

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> adjList;
    unordered_map<int, int> mark;
    int numEdges, numNodes;

public:
    Graph(int N) : numEdges(0), numNodes(N) {
        for (int i = 0; i < N; i++) {
            adjList[i];
            mark[i] = UNVISITED;
        }
    }

    void setEdge(int i, int j, int wt) {
        adjList[i].emplace_back(j, wt);
        numEdges++;
    }

    void dijkstra(int s, int D[]) {
        int P[numNodes]; // P array for storing predecessors
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        int p, v;

        for (int i = 0; i < numNodes; i++) {
            D[i] = INF;
            mark[i] = UNVISITED;
            P[i] = -1; // Initialize P array
        }

        H.push({0, {s, s}});
        D[s] = 0;

        for (int i = 0; i < numNodes; i++) {
            do {
                if (H.empty()) return;
                auto top = H.top(); H.pop();
                p = top.second.first;
                v = top.second.second;
            } while (mark[v] == VISITED);

            if (v == -1) return;
            mark[v] = VISITED;
            P[v] = p;

            for (auto& neighbor : adjList[v]) {
                int w = neighbor.first;
                int weight = neighbor.second;
                if (mark[w] != VISITED && D[w] > D[v] + weight) {
                    D[w] = D[v] + weight;
                    H.push({D[w], {v, w}});
                }
            }
        }
    }
};

int main() {
    int N = 5; // Número de nós
    Graph g(N);

    g.setEdge(0, 1, 10);
    g.setEdge(0, 2, 3);
    g.setEdge(0, 3, 20);
    g.setEdge(1, 3, 5);
    g.setEdge(2, 1, 2);
    g.setEdge(2, 4, 15);
    g.setEdge(3, 4, 11);
    
    int D[N];
    g.dijkstra(0, D);

    cout << "Distâncias mínimas a partir do nó 0:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Distância até o nó " << i << ": " << D[i] << endl;
    }

    return 0;
}
