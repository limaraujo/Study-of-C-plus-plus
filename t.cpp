#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, n;
    cin >> W >> n;

    vector<int> weights(n + 1);
    vector<int> values(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i]] + values[i]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][W] << endl;
    
    return 0;
}
