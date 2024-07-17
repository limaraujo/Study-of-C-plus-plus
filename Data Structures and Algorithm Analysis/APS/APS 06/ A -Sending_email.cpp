#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
#define UNVISITED 0
#define VISITED 1

class Graph{
private:
    vector<vector<pair<int,int>>> adjList;
    vector<int> mark;
    int numNodes, numEdges;

public:
    Graph(int N) : numNodes(N), numEdges(0), mark(N, UNVISITED), adjList(N) {}
    
    void setEdge(int i, int j, int wt){
        adjList[i].emplace_back(j, wt);
        adjList[j].emplace_back(i, wt);
        numEdges++;
    }

    void dijkstra(int s, vector<int>& D){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> H;
        vector<int> P(numNodes, -1); 
        int v, p;

        for(int i = 0; i < numNodes; i++){
            D[i] = INF; mark[i] = UNVISITED;
        }

        H.push({0, {s, s}}); D[s] = 0;
        
        for(int i = 0; i < numNodes; i++) {
            do {
                if (H.empty()) return;
                auto top = H.top(); 
                H.pop();
                p = top.second.first;
                v = top.second.second;
            } while (mark[v] == VISITED);

            mark[v] = VISITED; P[v] = p;
            for(auto neighbor : adjList[v]) {
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
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int N, n, m, S, T;
    cin >> N;

    for (int caseNum = 1; caseNum <= N; caseNum++) {
        cin >> n >> m >> S >> T;
        Graph Hogwarts(n);
        vector<int> D(n);

        for (int j = 0; j < m; j++) {
            int u, v, wt;
            cin >> u >> v >> wt;
            Hogwarts.setEdge(u, v, wt);
        }

        Hogwarts.dijkstra(S, D);

        if (D[T] == INF) {
            cout << "Case #" << caseNum << ": unreachable" << endl;
        } else {
            cout << "Case #" << caseNum << ": " << D[T] << endl;
        }
    }

    return 0;
}
