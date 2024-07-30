#include <bits/stdc++.h>
using namespace std;

void solve(int& numCase){
        int n;cin >> n;
        int coins[n+1];
        int F[n+1] = {0};

        coins[0] = 0;
        
        for(int i = 1; i < n+1; i++){
            cin >> coins[i];
        }

        F[1] = coins[1];

        for(int i = 2; i <= n; i++){
            F[i] = max(coins[i]+F[i-2], F[i-1]);
        }

        vector<int> escolhas;
        for(int i = n; i > 0; ){
            if (i == 1 || F[i] != F[i-1]) {
                escolhas.push_back(coins[i]);
                i -= 2;
            } else {
                i--;
            }
        }

        reverse(escolhas.begin(), escolhas.end());
        
        cout << "Caso " << numCase <<": "; 

        for(int i = 0; i < escolhas.size(); i++){
            if(i != 0 && i != escolhas.size()){
                cout << "+";
            }
            cout << escolhas[i];
        }
        if(n!=0){
            cout<< "=" << F[n] << endl;
        }else{
            cout<< "0=0" << endl;
        }
        numCase++;
}

int main(){
    int c, n; cin >> c;
    int numCase = 1;

    while(c--){
        solve(numCase);
    }

    return 0;
}