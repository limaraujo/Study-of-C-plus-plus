#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
#define VISITED 1
#define UNVISITED 0

class Graph {
private:
    unordered_map<string, vector<string>> adjList;
    unordered_set<string> allContestants;
    unordered_map<string, int> rank;
    unordered_map<string, int> mark;
    int numEdge;
    int numNode;

public:
    Graph(): numEdge(0), numNode(0) {}

    void setEdge(string u, string v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        allContestants.insert(u);
        allContestants.insert(v);
        numEdge++;
    }

    void BFS(string start) {
        queue<string> Q;
        Q.push(start);
        rank[start] = 0;
        mark[start] = VISITED;

        while (!Q.empty()) {
            string u = Q.front();
            Q.pop();

            for (string v : adjList[u]) {
                if (mark[v] == UNVISITED) {
                    mark[v] = VISITED;
                    rank[v] = rank[u] + 1;
                    Q.push(v);
                }
            }
        }
    }

    void printRanks() {
        vector<pair<string, int>> contestants;

        for (auto& contestant : allContestants) {
            if (rank.find(contestant) != rank.end()) {
                contestants.push_back({contestant, rank[contestant]});
            } else {
                contestants.push_back({contestant, INF});
            }
        }

        sort(contestants.begin(), contestants.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        cout << contestants.size() << endl;
        for (auto& contestant : contestants) {
            cout << contestant.first << " ";
            if (contestant.second == INF) {
                cout << "undefined" << endl;
            } else {
                cout << contestant.second << endl;
            }
        }
    }
};

void addEdges(Graph& G, string a, string b, string c) {
    G.setEdge(a, b); G.setEdge(b, c); G.setEdge(a, c);
}

void solve() {
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        Graph chupa_gambazada;
        for (int i = 0; i < N; ++i) {
            string a, b, c;
            cin >> a >> b >> c;
            addEdges(chupa_gambazada, a, b, c);
        }

        chupa_gambazada.BFS("Ahmad");
        chupa_gambazada.printRanks();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    solve();

    return 0;
}
