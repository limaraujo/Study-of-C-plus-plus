#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    unordered_map<int, vector<pair<int, int>>> adjList;
    unordered_map<int, int> mark;
    int numNodes, numEdges;

public:
    Graph(int N) : numNodes(N), numEdges(0) {
        for (int i = 0; i < N; i++) {
            adjList[i];
            mark[i] = UNVISITED;
        }
    }

    void setEdge(int i, int j, int wt) {
        adjList[i].emplace_back(j, wt);
        numEdges++;
    }

    int weight(int i, int j) {
        for (auto& neighbor : adjList[i]) {
            if (neighbor.first == j) {
                return neighbor.second;
            }
        }
        return -1;
    }

    void Floyd(vector<vector<int>>& D) {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (i == j) {
                    D[i][j] = 0;
                } else if (weight(i, j) != 0) {
                    D[i][j] = weight(i, j);
                } else {
                    D[i][j] = INF;
                }
            }
        }

        for (int k = 0; k < numNodes; k++) {
            for (int i = 0; i < numNodes; i++) {
                for (int j = 0; j < numNodes; j++) {
                    if (D[i][k] != INF && D[k][j] != INF && D[i][j] > D[i][k] + D[k][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }
    }

    void printDistances(vector<vector<int>>& D) {
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                if (D[i][j] == INF) {
                    cout << "[INF] ";
                } else {
                    cout << "[" << setw(3) <<D[i][j] << "] ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int numNodes = 4;
    Graph g(numNodes);
    g.setEdge(0, 1, 5);
    g.setEdge(0, 3, 10);
    g.setEdge(1, 2, 3);
    g.setEdge(2, 3, 1);

    vector<vector<int>> D(numNodes, vector<int>(numNodes, INF));
    g.Floyd(D);

    cout << "Shortest distances matrix:" << endl;
    g.printDistances(D);

    return 0;
}
