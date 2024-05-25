#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, x, y, r; int area_coberta = 0;
    cin >> n >> m >> s;

    while(s>0){
        cin >> x >> y >> r; 

        int Xo = max(1, x - r);
        int Xi = min(n, x + r);
        int Yo = max(1, y - r);
        int Yi = min(m, y + r);

        area_coberta +=(Xi - Xo + 1)*(Yi - Yo + 1);
        s--;
    }
    int media = area_coberta/(n*m);
    cout << media;

    return 0;
}
