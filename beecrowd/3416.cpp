#include <bits/stdc++.h>
using namespace std;

int main (){
    int n,l,d;
    cin >> n >> l >> d;

    int t = ceil((double(n*d))/(l*1000));
    cout << t*l;
    
    return 0;
}