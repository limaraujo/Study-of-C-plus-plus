#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;
    vector<int> mark;
    vector<int> pred;
    int numEdge;

    int n() { return matrix.size(); }

public:
    Graph(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n, 0));
        mark = vector<int>(n, 0);
        pred = vector<int>(n, -1);
        numEdge = 0;
    }

    int first(int v) {
        for (int i = 0; i < n(); i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return n();  // Retorna 'n' se não houver vizinho.
    }

    int next(int v, int w) {
        for (int i = w + 1; i < n(); i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return n();  // Retorna 'n' se não houver próximo vizinho.
    }

    void setEdge(int i, int j, int wt) {
        if (wt == 0) return;
        if (matrix[i][j] == 0) {
            numEdge++;
            matrix[i][j] = wt;
            matrix[j][i] = wt; // Aresta bidirecional para grafos não direcionados.
        }
    }

    void delEdge(int i, int j) {
        if (matrix[i][j] != 0) {
            numEdge--;
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }

    bool isEdge(int i, int j) {
        return matrix[i][j] != 0;
    }

    int weight(int i, int j) {
        return matrix[i][j];
    }

    void setMark(int v, int val) {
        mark[v] = val;
    }

    int getMark(int v) {
        return mark[v];
    }

    void preVisit(int v) {
        cout << v << " ";
    }

    void postVisit(int v) {
        cout << "Post-visit: " << v << endl;
    }

    void DFS(int v) {
        preVisit(v);
        setMark(v, 1);
        int w = first(v);
        while (w < n()) {
            if (getMark(w) == 0) {
                pred[w] = v;
                DFS(w);
            }
            w = next(v, w);
        }
    }

    void graphTraverseDFS(int i) {
        for (int v = 0; v < n(); v++) {
            setMark(v, 0);
            pred[v] = -1;
        }
        DFS(i);
        cout << endl;
    }

    void BFS(int v) {
        queue<int> Q;
        Q.push(v);
        setMark(v, 1);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            preVisit(u);
            int w = first(u);
            while (w < n()) {
                if (getMark(w) == 0) {
                    setMark(w, 1);
                    pred[w] = u;
                    Q.push(w);
                }
                w = next(u, w);
            }
        }
    }

    void graphTraverseBFS(int i) {
        for (int v = 0; v < n(); v++) {
            setMark(v, 0);
            pred[v] = -1;
        }
        BFS(i);
        cout << endl;
    }

    void printPred() {
        for (auto i : pred) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, q, i, j;
    string op;
    cin >> n >> q;
    Graph Hogwarts(n);

    while (q--) {
        cin >> op;
        if (op == "add") {
            cin >> i >> j;
            Hogwarts.setEdge(i, j, 1);
        } else if (op == "BFS") {
            cin >> i;
            Hogwarts.graphTraverseBFS(i);
            cout << "Predecessores" << endl;
            Hogwarts.printPred();
        } else if (op == "DFS") {
            cin >> i;
            Hogwarts.graphTraverseDFS(i);
        }
    }

    return 0;
}
