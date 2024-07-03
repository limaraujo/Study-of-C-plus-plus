#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numNode;
    vector<vector<int>> adjList;
    vector<int> inDegree;
    vector<int> topoOrder;

public:
    Graph(int n) : numNode(n), adjList(n + 1), inDegree(n + 1, 0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    bool topologicalSort() {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 1; i <= numNode; ++i) {
            if (inDegree[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            topoOrder.push_back(u);

            for (int v : adjList[u]) {
                if (--inDegree[v] == 0) {
                    pq.push(v);
                }
            }
        }

        return topoOrder.size() == numNode;
    }

    void printTopoOrder() {
        if (!topologicalSort()) {
            cout << "Sandro fails." << endl;
        } else {
            for (int i = 0; i < numNode; ++i) {
                cout << topoOrder[i];
                if (i < numNode - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        G.addEdge(x, y);
    }

    G.printTopoOrder();

    return 0;
}
