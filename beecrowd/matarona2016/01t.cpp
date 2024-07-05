#include <bits/stdc++.h>
using namespace std;
 
int main() {
    double h,p,v;
    cin >> h >> p;
    
    v = double(h)/double(p);
    
    cout << fixed << setprecision(2) << v << endl;
    
    return 0;
}