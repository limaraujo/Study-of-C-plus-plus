#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    long double A, B, C, t, p;
    cin >> A >> B >> C;
    char x; cin >> x;
    if (x == 'A') {
        p = B * (3.0L / 5)* 2.5L + C* 2.5;
        t = A + floor(p);
    } else if (x == 'B') {
        p = A * (2.0L / 5) * (5.0L / 3) + C * (5.0L / 3);
        t = B + floor(p);
    } else {
        p = A * (2.0L / 3)* (3.0L / 5) + B* (3.0L / 5) ;
        t = C + floor(p);
    }
    cout << setprecision(20) << t << endl;
    return 0;
}