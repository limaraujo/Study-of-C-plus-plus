#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    
    if(a==b || a==c || b ==c ){
        cout << "S" << endl;
    }else if(a + b == c || a + c == b || b + c == a){
        cout << "S" << endl;
    }else if(a - b == c || a - c == b || b - c == a){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }


    return 0;
}