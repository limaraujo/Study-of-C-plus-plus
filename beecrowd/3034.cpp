#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& viewpoints, int n, int c) {
    int start = 0, max_count = 1;

    for (int i = 0; i < n; i++) {
        if(viewpoints[i] - viewpoints[i-1] <= c){
            start++;
            if(start > max_count){
                max_count = start;
            }
        }else{
            start = 1;
        }
    }
    cout << max_count << endl;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> viewpoints(n);

    for (int i = 0; i < n; i++) {
        cin >> viewpoints[i];
    }

    solve(viewpoints, n, c);

    return 0;
}
