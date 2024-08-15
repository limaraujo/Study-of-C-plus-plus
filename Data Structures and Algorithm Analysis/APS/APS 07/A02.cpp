#include <bits/stdc++.h>
using namespace std;

#define S "SUCCESS"
#define I "IMPOSSIBLE"

pair<int, int> moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n;

bool solve(int xi, int yi, int s, vector<vector<char>>& labirinto) {
    if (s < 0) return false;
    for (auto move : moves) {
        int x = xi + move.first;
        int y = yi + move.second;

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (labirinto[x][y] == 'x') return true;
            if (labirinto[x][y] != '#') {
                char temp = labirinto[x][y];
                labirinto[x][y] = '#';  // Marca como visitado
                if (temp == '.') {
                    if (solve(x, y, s, labirinto)) return true;
                }
                if (temp == 's') {
                    if (solve(x, y, s - 1, labirinto)) return true;
                }
                labirinto[x][y] = temp; // Desmarca a visita
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
   char c; int j;

    cin >> n >> m >> j;
    vector<vector<char>> labirinto(n, vector<char>(m));
    pair<int, int> inicio;
    

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> c;
            if (c == '@') { 
                inicio = {i, k};
            }
            labirinto[i][k] = c;
        }
    }

    cout << (solve(inicio.first, inicio.second, j / 2, labirinto) ? S : I) << endl;

    return 0;
}
