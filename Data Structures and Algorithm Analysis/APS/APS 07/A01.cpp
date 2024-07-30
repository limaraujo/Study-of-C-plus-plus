#include <bits/stdc++.h>
using namespace std;

#define CASAON 1
#define CASAOFF -1
#define VISITED 0

pair<int, int> movimentos[] = {
    {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2},
    {1, 2}, {1, -2}, {2, 1}, {2, -1}
};

void moves(int xi, int yi, int cnt, int& menor, int table[10][10], int N) {
    for (auto [xf, yf] : movimentos) {
        int x = xi + xf;
        int y = yi + yf;
        if (x >= 0 && x < N && y >= 0 && y < 10 && table[x][y] == CASAON) {
            table[x][y] = VISITED;
            moves(x, y, cnt + 1, menor, table, N);
            table[x][y] = CASAON;
        }
    }
    if (cnt > menor) {
        menor = cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int caseNumber = 1;
    int N;

    while (cin >> N && N != 0) {
        int table[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                table[i][j] = CASAOFF;
            }
        }

        int totalCasas = 0;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            totalCasas += b;
            for (int j = 0; j < b; j++) {
                table[i][a + j] = CASAON;
            }
        }

        int menor = 0;
        table[0][0] = VISITED;
        moves(0, 0, 1, menor, table, N);

        int naoVisitadas = totalCasas - menor;
        cout << "Case " << caseNumber++ << ", " << naoVisitadas;
        if (naoVisitadas == 1) {
            cout << " square";
        } else {
            cout << " squares";
        }
        cout << " can not be reached." << endl;
    }

    return 0;
}





