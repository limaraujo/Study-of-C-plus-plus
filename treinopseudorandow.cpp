#include <bits/stdc++.h>
using namespace std;

struct Element{
    int valor;
    bool occupied;
    Element() : valor(-1), occupied(false){};
    Element(int it) : valor(it), occupied(true){}; 
};

typedef struct Dictionary{
    int size, currcnt;
    Element* table;
    int* Perm;

    Dictionary(int sz) : size(sz), currcnt(sz), table (new Element[sz]){
        Perm = new int[8]{2, 6, 7, 3, 1, 4, 5};
    }

    int hashing(int k){
        int v = k - (size*floor(k/size));
        return v;
    }

    int find(int k){
        int idx = hashing(k);
        int startIdx = idx;

        for(int j = 1 ; table[idx].valor != - 1 && j < size; j++){
            if(table[idx].valor == k){
                return idx;
            }
            int p = Perm[j-1];
            idx = (startIdx + p) % size;
        }
        if(table[idx].valor == k){
            return idx;
        }
        return -1;
    }

    void insert(int k){
        if(currcnt >= size){
            return;
        }
        
        int idx = hashing(k);
        int startIdx = idx;
        int j = 1;

        while(table[idx].valor != -1){
            if(table[idx].valor == k) {return;}

                int p = Perm[j++ -1];
                idx = (startIdx + p) % size;
            
            if(j == size && table[idx].valor != -1){
                return;
            }

        table[idx] = Element(k);
        currcnt++;
        }

    }

    int remove(int k){
        int pos = find(k);
        if(currcnt == 0 || pos == -1){
            return -1;
        }
        int temp = table[pos].valor;
        table[pos].valor = -1;
        currcnt--;
        return temp;
    }
}Dictionary;
