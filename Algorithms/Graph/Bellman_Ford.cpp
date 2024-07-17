#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> adjList;
    int numNodes;
    bool negative_cycle;

public:
    Graph(int N) : numNodes(N), negative_cycle(false) {
        for (int i = 0; i < N; i++) {
            adjList[i];
        }
    }

    void setEdge(int i, int j, int wt) {
        adjList[i].emplace_back(j, wt);
    }

    void BellmanFord(int s, int D[]) {
        for (int i = 0; i < numNodes; i++) {
            D[i] = INF;
        }

        D[s] = 0;

        for (int k = 0; k < numNodes - 1; k++) {
            for (int i = 0; i < numNodes; i++) {
                for (auto neighbor : adjList[i]) {
                    int j = neighbor.first;
                    int wt = neighbor.second;
                    if (D[j] > D[i] + wt) {
                        D[j] = D[i] + wt;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < numNodes; i++) {
            for (auto neighbor : adjList[i]) {
                int j = neighbor.first;
                int wt = neighbor.second;
                if (D[j] > D[i] + wt) {
                    negative_cycle = true;
                }
            }
        }
    }
};

int main() {
    Graph g(5);

    g.setEdge(0, 1, -1);
    g.setEdge(0, 2, 4);
    g.setEdge(1, 2, 3);
    g.setEdge(1, 3, 2);
    g.setEdge(1, 4, 2);
    g.setEdge(3, 1, 1);
    g.setEdge(3, 2, -5);
    g.setEdge(4, 3, -3);

    int D[5];

    g.BellmanFord(0, D);

    for (int i = 0; i < 5; i++) {
        cout << D[i] << " ";
    }
    cout << endl;

    return 0;
}
