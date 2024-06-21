#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Dictionary {
    int size;
    int currcnt;
    vector<string> table;

public:
    Dictionary(int sz) : size(sz), currcnt(0), table(sz) {}

    int Hash(const string& k) {
        int i = 1, chave = 0;
        for (char c : k) {
            chave += c * i++;
        }
        return (19 * chave) % size;
    }

    int find(const string& k) {
        int idx, startIdx = Hash(k);
        for (int j = 0; j < 20; j++) {
            idx = (startIdx + (23 * j) + (j * j)) % size;
            if (table[idx] == k) {
                return idx;
            }
        }
        return -1;
    }

    void insert(const string& k) {
        if (currcnt >= size) {
            return;
        }
        int idx, startIdx = Hash(k);
        if (find(k) != -1) {
            return;
        }
        for (int j = 0; j < 20; j++) {
            idx = (startIdx + (23 * j) + (j * j)) % size;
            if (table[idx].empty() || table[idx] == "REMOVIDO") {
                table[idx] = k;
                currcnt++;
                break;
            }
        }
    }

    void remove(const string& k) {
        int pos = find(k);
        if (currcnt == 0 || pos == -1) {
            return;
        }
        table[pos] = "REMOVIDO";
        currcnt--;
    }

    void clear() {
        fill(table.begin(), table.end(), "");
        currcnt = 0;
    }

    void printKeysOccupied() {
        cout << currcnt << endl;
        for (int i = 0; i < size; i++) {
            if (!table[i].empty() && table[i] != "REMOVIDO") {
                cout << i << ":" << table[i] << endl;
            }
        }
    }
};

void solve(Dictionary& dict) {
    int cases;
    cin >> cases;

    for (int n = 0; n < cases; n++) {
        int op;
        cin >> op;

        for (int m = 0; m < op; m++) {
            string op;
            cin >> op;
            if (op.substr(0, 3) == "ADD") {
                dict.insert(op.substr(4));
            } else if (op.substr(0, 3) == "DEL") {
                dict.remove(op.substr(4));
            }
        }

        dict.printKeysOccupied();
        dict.clear();
    }
}

int main() {
    Dictionary dict(101);
    solve(dict);
    return 0;
}
