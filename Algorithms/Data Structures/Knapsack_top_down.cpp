#include <bits/stdc++.h>
using namespace std;

int MFKnapsack(int i, int j, vector<int>& w, vector<int>& v, vector<vector<int>>& F) {
    if (F[i][j] < 0) {
        int value;
        if (j < w[i]) {
            value = MFKnapsack(i - 1, j, w, v, F);
        } else {
            value = max(MFKnapsack(i - 1, j, w, v, F), v[i] + MFKnapsack(i - 1, j - w[i], w, v, F));
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int S, N;
    cin >> S >> N;
    
    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }
    
    vector<vector<int>> F(N + 1, vector<int>(S + 1, -1));
    for (int i = 0; i <= N; i++) {
        F[i][0] = 0;
    }
    for (int j = 0; j <= S; j++) {
        F[0][j] = 0;
    }

    cout << MFKnapsack(N, S, W, V, F) << endl;
    
    return 0;
}
