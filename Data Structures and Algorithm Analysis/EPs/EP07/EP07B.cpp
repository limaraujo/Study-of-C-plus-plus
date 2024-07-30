#include <bits/stdc++.h>
using namespace std;

bool findSubset(vector<int>& A, vector<int>& subset, int index, int d) {
    if (d == 0) {
        return true;
    }
    if (d < 0 || index == A.size()) {
        return false;
    }
    subset.push_back(A[index]);
    if (findSubset(A, subset, index + 1, d - A[index])) {
        return true;
    }
    subset.pop_back();
    return findSubset(A, subset, index + 1, d);
}

int main() {
    int c, n, d;
    cin >> c;
    for (int caseNum = 1; caseNum <= c; ++caseNum) {
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }-
        cin >> d;

        vector<int> subset;
        if (findSubset(A, subset, 0, d)) {
            cout << "{";
            for (int i = 0; i < subset.size(); ++i) {
                if (i > 0) cout << ", ";
                cout << subset[i];
            }
            cout << "}\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
