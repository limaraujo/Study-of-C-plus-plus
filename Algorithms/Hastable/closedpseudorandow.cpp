#include <bits/stdc++.h>
using namespace std;

struct Element{
    int valor;
    bool occupied;
    
    Element() : valor(-1), occupied(false){}
    Element(int it) : valor(it), occupied(true){}
};

typedef struct Dictionary{
    int size;
    int currcnt;
    Element* table;
    int* Perm;
    
    Dictionary(int sz) : size(sz), currcnt(0), table(new Element[sz]) {
        Perm = new int[8]{2, 6, 7, 3, 1, 4, 5};
    }

    int hashing(int k){
        int v = k - (size*floor(k/size));
        return v;
    }

    int find(int k) {
        int idx = hashing(k);
        int startIdx = idx;

        for (int j = 1; table[idx].occupied && j < size; j++) {
            if (table[idx].valor == k) {
                return idx;
            }
            int p = Perm[j - 1];
            idx = (startIdx + p) % size;
        }
        
        if (table[idx].valor == k) {
            return idx;
        }
        
        return -1;
    }

    void insert(int k){
        if (currcnt >= size) {
            return;
        }
        int idx = hashing(k);
        int startIdx = idx;
        int j = 1;

        while(table[idx].valor != -1){
            if(table[idx].valor == k){return;}

            int p = Perm[j++ -1];
            idx = (startIdx + p) % size;

            if(j == size && table[idx].valor != -1){return;}
        }
        table[idx] = Element(k);
        currcnt++;         
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

    vector<int> getKeys() {
        vector<int> keys;
        for (int i = 0; i < size; ++i) {
            if (table[i].occupied && table[i].valor != -1) {
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


}Dictionary;

int main() {
    // Criando uma instância do dicionário com tamanho 8
    Dictionary dict(8);

    // Inserindo algumas chaves no dicionário
    dict.insert(2);  // Deve ser inserido na posição 2
    dict.insert(4);  // Deve ser inserido na posição 4
    dict.insert(8);  // Deve ser inserido na posição 0
    dict.insert(16); // Deve ser inserido na posição 2 após a sondagem pseudo-aleatória
    dict.insert(32);
    dict.insert(64);
    dict.insert(128);
    dict.insert(256);

    // Verificando o número atual de elementos na tabela de dispersão
    cout << "Numero atual de elementos na tabela: " << dict.getCurrentSize() << endl;

    dict.printElements();


    // Verificando as chaves presentes na tabela de dispersão
    vector<int> keys = dict.getKeys();
    cout << "Chaves presentes na tabela: ";
    for (int key : keys) {
        cout << key << " ";
    }
    cout << endl;

    // Removendo uma chave e verificando se foi removida com sucesso
    int removed_key = 4;
    int removed_value = dict.remove(removed_key); 
    // Verificando o número atual de elementos na tabela de dispersão após a remoção
    cout << "Numero atual de elementos na tabela apos remocao: " << dict.getCurrentSize() << endl;

    // Verificando as chaves presentes na tabela de dispersão após a remoção
    keys = dict.getKeys();
    cout << "Chaves presentes na tabela apos remocao: ";

    for (int key : keys) {
        cout << key << " ";
    }
    cout << endl;

    dict.printElements();

    removed_key = 256;
    removed_value = dict.remove(removed_key); 
    // Verificando o número atual de elementos na tabela de dispersão após a remoção
    cout << "Numero atual de elementos na tabela apos remocao: " << dict.getCurrentSize() << endl;

    // Verificando as chaves presentes na tabela de dispersão após a remoção
    keys = dict.getKeys();
    cout << "Chaves presentes na tabela apos remocao: ";

    for (int key : keys) {
        cout << key << " ";
    }
    cout << endl;

    dict.printElements();

    dict.insert(5);
    dict.printElements();

    int x = dict.find(5);
    cout << dict.table[x].valor << "\n";
    return 0;
}