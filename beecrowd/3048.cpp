#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt = 0;
    int sq[n];

    for(int i = 0; i < n; i++){
        cin >> sq[i];
    }

    for(int i = 0; i < n; i++){
        if(sq[i] != sq[i+1]){
            cnt++; 
        }
    }
    cout << cnt << endl;  
      
    return 0;
}