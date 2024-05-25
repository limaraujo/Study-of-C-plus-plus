#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

void div7(long long x);

int main(){
    long long x;
    cin >> x;
    div7(x);
    return 0;
}

void div7(long long x){
    if (x > 9){
        cout << x << endl;
    }
    while (x>9){
        int r = x % 10;
        x = x/10;
        x = x * 3 + r;
        if (x > 9){
            cout << x << endl;
        }
    }
    cout << x << endl;
}