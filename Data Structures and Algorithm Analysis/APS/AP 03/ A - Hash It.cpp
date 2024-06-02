#include <bits/stdc++.h>
using namespace std;

struct Element{
    string valor;
    bool occupied;
    
    Element() : valor(""), occupied(false){}
    Element(string e) : valor(e), occupied(true){}
};

typedef struct Dictionary{
    int size;
    int currcnt;
    Element* table;

    Dictionary(int sz) : size(sz), currcnt(0), table(new Element[sz]){}

    int Hash(string k){
        int i = 1; int chave = 0;
        for(char c: k){
            chave += c* i ++;
        }
        return (19*chave) %101;
    }


    int find(string k){
        int idx = Hash(k);
        int startIdx = idx;

        for(int j = 1; table[idx].occupied && j < 20; j++){
            if(table[idx].valor == k){
                return idx;
            }
            int p = (j*j) + (23 * j++);
            idx = (startIdx + p) % size;
        }
        
        if(table[idx].valor == k){
            return idx;
        }

        return -1;
    }

    void insert(string k){
        if (currcnt >= size) {
            return;
        }
        int idx = Hash(k);
        int startIdx = idx;
        int j = 1;

        while( table[idx].valor != ""){
            if(table[idx].valor == k){return;}

            int p = (j*j) + (23 * j++);
            idx = (startIdx + p) % size;

            if(j == 20 && table[idx].valor != ""){return;}
        }

        table[idx] = Element(k);
        currcnt++;
    }

    void remove(string k){
        int pos = find(k);

        if(currcnt == 0 || pos == -1){return;}
        
        table[pos].valor = "";
        currcnt--;
    }

    void clean() {
        for (int i = 0; i < size; i++) {
            table[i] = Element();
        }
        currcnt = 0;
    }

    void printKeysOccupieds(){
        cout << currcnt << endl;
        for(int i = 0; i < size; i++){
            if(table[i].valor != ""){
                cout << i << ": " << table[i].valor << endl;
            }
        }
        cout << endl;
    }
};

void solve (Dictionary dict){
    int cases, op; cin >> cases;
    string operation;string valor;

    for(int n = 0; n < cases; n++){
        cin >> op;

        for(int m = 0; m < op; m++){
            getline(cin, operation, ':');
            getline(cin, valor);
            if(operation == "ADD"){
                dict.insert(valor);
            }else{
                dict.remove(valor);
            }
        }

        dict.printKeysOccupieds();
        dict.clean();
    }
    
}

int main (){
    Dictionary dict(101);
    solve(dict);
}