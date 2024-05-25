#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, k, x;
    for(int i = 0; i <= 2*n; i++){
        if((i*i-k) % (2*n+1) == 0){
            x = (i*i);
        }
    }
    cout << x << endl;
    return 0;
}
