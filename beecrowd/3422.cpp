#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, o; cin >> n;
    string t;

    for (int  i = 0; i < n; i++){
        cin >> o >> t;
        if(t == "1T"){
            cout << (o <= 45 ? to_string(o) : "45+" + to_string(o % 45)) << endl;
        }else{
            o += 45;
            cout << (o <= 90 ? to_string(o) : "90+" + to_string(o % 90)) << endl;
        }
    }
    
}