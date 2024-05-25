#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return mdc(b, a % b);
    }
}

int main() {
    int i;
    cin >> i;
    while (i > 0) {
        int n1, n2, d1, d2, nr, dr;
        char ope, b;
        cin >> n1 >> b >> d1 >> ope >> n2 >> b >> d2;
        
        // Realizar a operação
        if (ope == '+') {
            nr = (n1 * d2 + n2 * d1);
            dr = (d1 * d2);
        } else if (ope == '-') {
            nr = (n1 * d2 - n2 * d1);
            dr = (d1 * d2);            
        } else if (ope == '*') {
            nr = (n1 * n2);
            dr = (d1 * d2);            
        } else if (ope == '/') {
            nr = (n1 * d2);
            dr = (n2 * d1);            
        }

        // Simplificar a fração resultante
        int divisor = mdc(abs(nr), abs(dr));
        nr /= divisor;
        dr /= divisor;
        
        if (dr < 0) {
            nr = -nr;
            dr = -dr;
        }

        cout << nr << '/' << dr << endl;

        i--;
    }

    return 0;
}
