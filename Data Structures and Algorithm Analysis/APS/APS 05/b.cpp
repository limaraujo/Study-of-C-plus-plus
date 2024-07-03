#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int,vector<int>> adjList;
    vector<int> inDegree, inTopoSort;
    int numNode;

public:
    Graph(int n) : numNode(n), adjList(n + 1), inDegree(n + 1, 0) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    bool graphTraverse(){
        priority_queue<int, vector<int>, greater<int>> nodes;

        for (int i = 1; i <= numNode; ++i) {
            if (inDegree[i] == 0) {
                nodes.push(i);
            }
        }

        topoSort(nodes);
        return inTopoSort.size() == numNode;
    }

    void topoSort(priority_queue<int, vector<int>, greater<int>>&s){
        if(s.empty()){return;}
        int w = s.top(); s.pop();
        inTopoSort.push_back(w);

            for (int v : adjList[w]) {
                if (--inDegree[v] == 0) {s.push(v);}
            }
        
        topoSort(s);
    }

    void complet() {
        if (!graphTraverse()) {
            cout << "Sandro fails." << endl;
        } else {
            for (int i = 0; i < inTopoSort.size(); ++i) {
                cout << inTopoSort[i] << (i != inTopoSort.size() - 1 ? " " : "\n");
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph chupa_gambazada(n);

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        chupa_gambazada.addEdge(x, y);
    }

    chupa_gambazada.complet();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    solve();

    return 0;
}
