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
        return 0;
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


}Dictionary;

int main() {
    Dictionary dict(650); 

    for(int i = 'a'; i <= 'z'; i++){
        for(int j = 'a'; j <= 'z'; j++){
            if(i != j){
                string s;
                s += char(i);
                s += char(j);
                dict.insert(s);
            }
        }
    }

    int cases; cin >> cases;
    string d;
    
    for(int n = 0; n < cases; n++){
        cin >> d;
        cout << dict.find(d) + 1 << endl;
    }
    return 0;
}



