#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>>& graph, int start, int end) {
    if (start == end) return 0;
    
    vector<int> distance(graph.size(), -1);
    queue<int> q;
    
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
                if (neighbor == end) {
                    return distance[neighbor];
                }
            }
        }
    }
    
    return -1;
}

int main() {
    int c;
    cin >> c;
    
    for (int k = 1; k <= c; ++k) {
        int v, a;
        cin >> v >> a;
        
        vector<vector<int>> graph(v);
        
        for (int i = 0; i < a; ++i) {
            int u, w;
            cin >> u >> w;
            graph[u].push_back(w);
        }
        
        int n;
        cin >> n;
        
        cout << "Caso " << k << endl;
        for (int i = 0; i < n; ++i) {
            int s, t;
            cin >> s >> t;
            cout << bfs(graph, s, t) << endl;
        }
    }
    
    return 0;
}
