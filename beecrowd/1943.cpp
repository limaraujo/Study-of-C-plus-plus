#include <bits/stdc++.h>
using namespace std;

int main(){
    int rank[9] = {0,1,3,5,10,25,50,100,101};
    int K; cin >> K;

    for(int i = 0; i <=9; i++){
        if(K > rank[i] && K <= rank[i+1]){
            cout << "Top " << rank[i+1] << endl;
            break;
        }
    }


    return 0;
}