#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    list<pair<int, int>> *adj;
    int numEdge, numNode;
    int* mark;

public:
    Graph(int n) {
        adj = new list<pair<int, int>>[n];
        numEdge = 0; numNode = n;
        mark = new int[n];
        memset(mark, 0, n * sizeof(int));
    }

    ~Graph() {
        delete[] adj;
        delete[] mark;
    }

    int n() const {
        return numNode;
    }
    
    int e() const {
        return numEdge;
    }

    int first(int v) const {
        if (adj[v].empty()) {
            return n();
        }
        return adj[v].front().first;
    }

    int next(int v, int w) const {
        auto it = adj[v].begin();
        while (it != adj[v].end() && it->first != w) {
            ++it;
        }
        if (it != adj[v].end()) {
            ++it;
            if (it != adj[v].end()) {
                return it->first;
            }
        }
        return n();
    }

    void setEdge(int i, int j, int wt) {
        if (wt == 0) return;
        adj[i].push_back({j, wt});
        numEdge++;
    }

    void delEdge(int i, int j) {
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            if (it->first == j) {
                adj[i].erase(it);
                numEdge--;
                break;
            }
        }
    }

    bool isEdge(int i, int j) const {
        for (const auto& neighbor : adj[i]) {
            if (neighbor.first == j) return true;
        }
        return false;
    }

    int weight(int i, int j) const {
        for (const auto& neighbor : adj[i]) {
            if (neighbor.first == j) return neighbor.second;
        }
        return 0;
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) const {
        return mark[v];
    }

    void preVisit(int v) const {
        cout << "Pre-visit: " << v << endl;
    }

    void postVisit(int v) const {
        cout << "Post-visit: " << v << endl;
    }

    void toposort(int v, stack<int>& s) {
        setMark(v, 1);
        int w = first(v);
        while (w != n()) {
            if (getMark(w) == 0) {
                toposort(w, s);
            }
            w = next(v, w);
        }
        s.push(v);
    }

    void graphTraverse(stack<int>& s) {
        for (int v = 0; v < n(); v++) {
            setMark(v, 0);
        }
        for (int v = 0; v < n(); v++) {
            if (getMark(v) == 0) {
                toposort(v, s);
            }
        }
    }
};

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    Graph g(n);
    stack<int> top;
    
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g.setEdge(u, v, 1);
    }
    g.graphTraverse(top);

    cout << "Topological Sort: ";
    printStack(top);

    g.delEdge(4, 6);

    for (int i = 0; i < n; i++) {
        g.setMark(i, 0);
    }

    stack<int> newTop;
    g.graphTraverse(newTop);

    cout << "Topological Sort after removing edge (4, 6): ";
    printStack(newTop);

    return 0;
}
