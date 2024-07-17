#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<int> mark;
    int numNodes;
    bool isConnected;

public:
    Graph(int N) : numNodes(N), adjList(N), mark(N, UNVISITED), isConnected(true) {}

    void setEdge(int i, int j, int wt) {
        adjList[i].emplace_back(j, wt);
        adjList[j].emplace_back(i, wt);
    }

    void Prim(int D[], int P[]) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        int p, v;

        fill(D, D + numNodes, INF);
        fill(P, P + numNodes, -1);
        fill(mark.begin(), mark.end(), UNVISITED);

        H.push({0, {0, 0}}); 
        D[0] = 0;

       for (int i = 0; i < numNodes; i++) {
            do {
                if (H.empty()) { 
                    isConnected = false; 
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

    bool isConnectedGraph() {
        for (int i = 0; i < numNodes; i++) {
            if (mark[i] == UNVISITED) {
                isConnected = false;
                break;
            }
        }
        return isConnected;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        Graph G(n);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            G.setEdge(u, v, w);
        }

        int D[n], P[n];
        G.Prim(D, P);
        
        bool isConnectedGraph = G.isConnectedGraph();

        if (isConnectedGraph) {
            int maxWeight = *max_element(D, D + n);
            cout << maxWeight << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
