#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    list<int> *adj;
    int numEdge, numNode;
    int* mark;

public:
    Graph(int n) {
        adj = new list<int>[n];
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
            return -1;
        }
        return adj[v].front();
    }

    int next(int v, int w) const {
        auto it = adj[v].begin();
        while (it != adj[v].end() && *it != w) {
            ++it;
        }
        if (it != adj[v].end()) {
            ++it;
            if (it != adj[v].end()) {
                return *it;
            }
        }
        return -1;
    }

    void setEdge(int i, int j, int wt) {
        if (wt == 0) return;
        adj[i].push_back(j);
        numEdge++;
    }

    void delEdge(int i, int j) {
        adj[i].remove(j);
        numEdge--;
    }

    bool isEdge(int i, int j) const {
        for (const auto& neighbor : adj[i]) {
            if (neighbor == j) return true;
        }
        return false;
    }

    int weight(int i, int j) const {
        // Assume weight is always 1 in this case
        for (const auto& neighbor : adj[i]) {
            if (neighbor == j) return 1;
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
        while (w != -1) {
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

    return 0;
}
