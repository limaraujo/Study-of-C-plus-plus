#include <bits/stdc++.h>

using namespace std;

struct Element {
    string valor;
    bool occupied;

    Element() : valor(""), occupied(false) {}
    Element(string s) : valor(s), occupied(true) {}
};

typedef  struct Dictionary {
    int size;
    int currcnt;
    Element* table;

    Dictionary(int sz) : size(sz), currcnt(0), table(new Element[sz]) {}

    int h(const string& k) const {
        int s = k.length(), sum = 0;
        for (int i = 0; i < s; ++i) {
            sum += k[i];
        }
        return sum % size;
    }

    int find(const string& k) {
        int idx = h(k);
        int startIdx = idx;

        while (table[idx].valor != "") {
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

    void insert(const string& k) {
        if (currcnt >= size) {
            return;
        }
        int idx = h(k);int startIdx = idx;
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

    string remove(const string& k) {
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

    int getCurrentSize() const {
        return currcnt;
    }

    void clean() {
        for (int i = 0; i < size; i++) {
            table[i] = Element();
        }
        currcnt = 0;
    }

    void printElements() const {
        for (int i = 0; i < size; ++i) {
            if (table[i].occupied) {
                cout << i << ": " << table[i].valor << endl;
            }
        }
        cout << endl;
    }
}Dictionary;

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Cria um dicionário com tamanho 1000
    Dictionary dict(1000);

    // Insere mil elementos
    for (int i = 0; i < 1000; ++i) {
        string key = "element_" + to_string(i);
        dict.insert(key);
    }

    // Imprime elementos após inserção
    cout << "Elementos após inserção:" << endl;
    dict.printElements();

    // Testa a busca de alguns elementos válidos
    cout << "Buscando por 'element_123': " << (dict.find("element_123") != -1 ? "Encontrado" : "Não Encontrado") << endl;
    cout << "Buscando por 'element_999': " << (dict.find("element_999") != -1 ? "Encontrado" : "Não Encontrado") << endl;

    // Testa a busca de alguns elementos inválidos
    cout << "Buscando por 'element_invalido': " << (dict.find("element_invalido") != -1 ? "Encontrado" : "Não Encontrado") << endl;
    cout << "Buscando por 'palavra_aleatoria': " << (dict.find("palavra_aleatoria") != -1 ? "Encontrado" : "Não Encontrado") << endl;

    // Remove um elemento
    cout << "Removendo 'element_456': " << dict.remove("element_456") << endl;

    // Imprime elementos após remoção
    cout << "Elementos após remoção:" << endl;
    dict.printElements();

    // Tamanho atual do dicionário
    cout << "Tamanho atual do dicionário: " << dict.getCurrentSize() << endl;

    // Limpa o dicionário
    dict.clean();

    return 0;
}

