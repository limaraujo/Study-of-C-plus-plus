//closed certo

#include <bits/stdc++.h>
using namespace std;

struct Entry {
    string valor;bool deleted;
    Entry() : valor(""), deleted(false) {}
};

struct Dictionary {
    int size; int currcnt; Entry* table;
    Dictionary(int sz) : size(sz), currcnt(0), table(new Entry[sz]) {}

    int Hash(string k) {
        int i = 1; int chave = 0;
        for (char c : k) {
            chave += c * i++;
        }
        return (19 * chave) % 101;
    }

    int find(string k) {
        int idx, startIdx = Hash(k);
        for (int j = 0; j < 20; j++) {
            idx = (startIdx + (23 * j) + (j * j)) % 101;
            if (table[idx].valor == k && !table[idx].deleted) {
                return idx;
            }
        }
        return -1;
    }

    void insert(string k) {
        if (currcnt >= size) {
            return;
        }
        int idx, startIdx = Hash(k);
        if (find(k) != -1) {
            return;
        }
        for (int j = 0; j < 20; j++) {
            idx = (startIdx + (23 * j) + (j * j)) % 101;
            if (table[idx].valor == "" || table[idx].deleted) {
                table[idx].valor = k;
                table[idx].deleted = false;
                currcnt++;
                break;
            }
        }
    }

    void remove(string k) {
        int pos = find(k);
        if (currcnt == 0 || pos == -1) { 
            return; 
        }
        table[pos].deleted = true;
        currcnt--;
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            table[i].valor.clear();
            table[i].deleted = false;
        }
        currcnt = 0;
    }

    void printKeysOccupied(){
        cout << currcnt << endl;
        for(int i = 0; i < size; i++){
            if(table[i].valor != "" && !table[i].deleted){
                cout << i << ":" << table[i].valor << endl;
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
            string op;cin >> op;
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
