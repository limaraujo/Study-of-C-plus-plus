#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int h,m,s;

    h  = n / 3600;
    n = n % 3600;
    m = n / 60;
    s = n % 60;
    
    cout << h << ":" << m << ":" << s << endl;
    return 0;
}
