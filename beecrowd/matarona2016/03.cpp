#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    vector<char> r1;
    vector<char> r2;

    getline(cin, S);

    for (char s : S) {
        if (s == 'a' || s == 'e' || s == 'i' ||
            s == 'o' || s == 'u') {
            r1.push_back(s);
        }
    }
    r2 = r1;
    reverse(r2.begin(), r2.end()); 

    cout << (r2 == r1 ? "S" : "N") << endl;

    return 0;
}
