#include <bits/stdc++.h>

using namespace std;

struct Element {
    string valor;  
    bool occupied; 

    Element() : valor(""), occupied(false) {}
    Element(string s) : valor(s), occupied(true) {}
};

typedef struct Dictionary {
    int size;      
    int currcnt;   
    Element* table; 

    Dictionary(int sz) : size(sz), currcnt(0), table(new Element[sz]) {}

    int h(string& k){
        int s = k.length(), sum = 0;
        for (int i = 0; i < s; ++i) {
            sum += k[i];
        }
        return sum % size;
    }

    int find(string& k) {
        int idx = h(k);
        int startIdx = idx;

        while (table[idx].occupied) {
            if (table[idx].valor == k) {
                return idx;
            }
            idx = (idx + 1) % size;
            if (idx == startIdx) {
                break;
            }
        }
        return -1; 
    }

    void insert(string& k) {
        if (currcnt >= size) {
            return;
        }
        int idx = h(k);
        int startIdx = idx;
        while (table[idx].valor != "") {
            if (table[idx].valor == k) {
                return; 
            }
            idx = (idx + 1) % size;
            if (idx == startIdx) {
                return;
            }
        }
        table[idx] = Element(k);
        currcnt++;
    }

    string remove(string& k) {
        int pos = find(k);
        if (currcnt == 0 || pos == -1) {
            return "-1";
        }
        string temp = table[pos].valor;
        table[pos].valor = "";
        currcnt--;
        return temp;
    }

    vector<string> getKeys() {
        vector<string> keys;
        for (int i = 0; i < size; ++i) {
            if (table[i].occupied) {
                keys.push_back(table[i].valor);
            }
        }
        return keys;
    }

    int getCurrentSize(){
        return currcnt;
    }

    void clean() {
        for (int i = 0; i < size; i++) {
            table[i] = Element();
        }
        currcnt = 0;
    }

    void printElements(){
        for (int i = 0; i < size; ++i) {
            if (table[i].occupied) {
                cout << i << ": " << table[i].valor << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    Dictionary dict(10); 

    string keys[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    for (string& key : keys) {
        dict.insert(key);
    }

    dict.printElements();

    string keyToRemove = "cab";
    cout << "Removing: " << dict.remove(keyToRemove) << endl;

    dict.printElements();

    vector<string> allKeys = dict.getKeys();
    cout << "Current keys: ";
    for (string& key : allKeys) {
        cout << key << " ";
    }
    cout << endl;

    keyToRemove = "acb";
    cout << "Removing: " << dict.remove(keyToRemove) << endl;

    dict.printElements();

    cout << "Current size: " << dict.getCurrentSize() << endl;

    return 0;
}



