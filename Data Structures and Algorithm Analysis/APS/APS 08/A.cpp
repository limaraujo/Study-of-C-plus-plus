#include <iostream>
#include <algorithm>
#include <cmath> // Para std::abs
using namespace std;

#define INF 1000000000 

int main() {
    int N, K;
    cin >> N >> K;
    
    int h[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    
    int dp[N + 1] = {INF}; 
    dp[1] = 0; 
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i + j <= N) {
                dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
