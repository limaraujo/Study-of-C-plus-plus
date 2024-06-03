#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int key;
    int valor;
    bool deleted;
    Entry() : key(-1), valor(-1), deleted(false) {}
    Entry(int k, int v) : key(k), valor(v), deleted(false) {}
};

struct Dictionary {
    int size;
    int currcnt;
    Entry* table;
    Dictionary(int sz) : size(sz), currcnt(0), table(new Entry[sz]) {}
    ~Dictionary() { delete[] table; }

    int Hash(int key) {
    int temp = (int) floor((((double) key) / ((double) size))); 
    return (key - (size * temp)); }

    int find(int k, int arrPerm[]) {
        int startIdx = Hash(k);
        int idx = startIdx;
        if (table[idx].key == k && !table[idx].deleted) {
            return idx;
        }
        for (int i = 1; i < size; i++) {
            int p = arrPerm[i - 1];
            idx = (startIdx + p) % size;
            if (table[idx].key == k && !table[idx].deleted) {
                return idx;
            }
        }
        return -1;
    }

    void insert(int k, int v, int arrPerm[]) {
        if (currcnt >= size || find(k, arrPerm) != -1) {
            return;
        }

        int startIdx = Hash(k);
        int idx = startIdx;

        if (table[idx].key == -1 || table[idx].deleted) {
            table[idx] = Entry(k, v);
            table[idx].deleted = false;
            currcnt++;
            return;
        }

        for (int j = 1; j < size; j++) {
            int p = arrPerm[j - 1];
            idx = (startIdx + p) % size;

            if (table[idx].key == -1 || table[idx].deleted) {
                table[idx] = Entry(k, v);
                table[idx].deleted = false;
                currcnt++;
                break;
            }
        }
    }

    void remove(int k, int arrPerm[]) {
        int pos = find(k, arrPerm);
        if (currcnt == 0 || pos == -1) {
            return;
        }
        table[pos].deleted = true;
        currcnt--;
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            table[i] = Entry();
        }
        currcnt = 0;
    }

    void printKeysOccupied() {
        cout << currcnt << endl;
        for (int i = 0; i < size; i++) {
            if (table[i].key != -1 && !table[i].deleted) {
                cout << i << ":" << table[i].valor << endl;
            }
        }
    }
};

int main() {
    int c;
    cin >> c;
    while (c != 0) {
        Dictionary dict(c);
        vector<int> arrPerm(c - 1);

        for (int i = 0; i < c - 1; i++) {
            cin >> arrPerm[i];
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            string opp;
            int key;
            cin >> opp >> key;
            if (opp == "add") {
                int valor;
                cin >> valor;
                dict.insert(key, valor, arrPerm.data());
            } else if (opp == "find") {
                int r = dict.find(key, arrPerm.data());
                if (r == -1) {
                    cout << r << endl;
                } else {
                    cout << r << " " << dict.table[r].valor << endl;
                }
            } else if (opp == "remove"){
                dict.remove(key, arrPerm.data());
            }
        }
        dict.clear();
        cin >> c;
    }
    return 0;
}
