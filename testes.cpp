#include <bits/stdc++.h>

using namespace std;

void f(int** G, int n) {
    int mark[n] = {0}; // Inicializa o vetor mark com zeros

    for (int i = 0; i < n; i++) {
        if (mark[i] == 0) {
            priority_queue<int, vector<int>, greater<int>> Q;
            Q.push(i); 
            mark[i] = 1;

            while (!Q.empty()) {
                int s = Q.top();
                Q.pop();

                for (int j = 0; j < n; j++) {
                    if (G[s][j] == 1 && mark[j] == 0) {
                        mark[j] = 1;
                        Q.push(j);
                    }
                }
            }
        }
    }
}

int main() {
    int n = 4;

    // Aloca a matriz G dinamicamente
    int** G = new int*[n];
    for (int i = 0; i < n; ++i) {
        G[i] = new int[n];
    }

    // Inicializa a matriz de adjacência
    G[0][0] = 0; G[0][1] = 1; G[0][2] = 0; G[0][3] = 0;
    G[1][0] = 1; G[1][1] = 0; G[1][2] = 1; G[1][3] = 1;
    G[2][0] = 0; G[2][1] = 1; G[2][2] = 0; G[2][3] = 1;
    G[3][0] = 0; G[3][1] = 1; G[3][2] = 1; G[3][3] = 0;

    f(G, n);

    // Libera a memória alocada
    for (int i = 0; i < n; ++i) {
        delete[] G[i];
    }
    delete[] G;

    return 0;
}
