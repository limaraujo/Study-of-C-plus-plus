#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S, N;
    cin >> S >> N;
    
    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    
    vector<vector<int>> F(N + 1, vector<int>(S + 1, 0));

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (i == 0 || j == 0) {
                F[i][j] = 0;
            } else if (W[i] <= j) {
                F[i][j] = max(F[i-1][j], V[i] + F[i-1][j - W[i]]);
            } else {
                F[i][j] = F[i-1][j];
            }
        }
    }

    cout << F[N][S] << endl;
    
    return 0;
}
