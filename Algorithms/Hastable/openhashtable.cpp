//open hastable
#include <bits/stdc++.h>
using namespace std;

int h(const string& k, int size) {
    int s = k.length(), sum = 0;
    for (int i = 0; i < s; ++i) {
        sum += k[i];
    }
    return abs(sum) % size;
}

typedef struct Hashtable {
    int size;
    int currcnt;
    vector<string> *table;

    Hashtable(int sz) : size(sz), currcnt(0) {
        table = new vector<string>[sz];
    }

    int find(const string& k) {
        int pos = h(k, size);
        for (int i = 0; i < table[pos].size(); i++){
            if (table[pos][i] == k) {
                return i;
            }
        }
        return -1;
    }

    void insert(const string& k) {
        if (find(k) == -1) {
            int pos = h(k, size);
            table[pos].push_back(k);
            currcnt++;
        }
    }

    string remove(string k){
        int pos = h(k,size);
        int idx = find(k);
        if(idx != -1){
            string temp = table[pos][idx];
            table[pos].erase(table[pos].begin() + idx);
            currcnt--;
            return temp;
            }
        return "";
    }

    int getCurrentSize(){
        return currcnt;
    }
    
    void clean() {
        for (int i = 0; i < size; i++) {
            table[i].clear();
        }
        currcnt = 0;
        table->clear();
    }

}Hashtable;

void runTests() {
    Hashtable ht(10); // Cria uma tabela hash com tamanho 10

    // Palavras que têm a mesma chave
    string palavra1 = "abc"; // soma ASCII: 97 + 98 + 99 = 294
    string palavra2 = "cab"; // soma ASCII: 99 + 97 + 98 = 294
    string palavra3 = "bca"; // soma ASCII: 98 + 99 + 97 = 294

    // Inserindo palavras na tabela
    ht.insert(palavra1);
    ht.insert(palavra2);
    ht.insert(palavra3);

    // Teste de inserção e busca
    cout << "Teste de insercao e busca:" << endl;
    cout << palavra1 << " encontrado? " << (ht.find(palavra1) != -1 ? "Sim" : "Nao") << endl;
    cout << palavra2 << " encontrado? " << (ht.find(palavra2) != -1 ? "Sim" : "Nao") << endl;
    cout << palavra3 << " encontrado? " << (ht.find(palavra3) != -1 ? "Sim" : "Nao") << endl;

    // Verificando se todas estão na mesma posição
    int pos1 = h(palavra1, ht.size);
    int pos2 = h(palavra2, ht.size);
    int pos3 = h(palavra3, ht.size);

    cout << "\nVerificacao das posicoes das palavras na tabela:" << endl;
    cout << palavra1 << " posicao: " << pos1 << endl;
    cout << palavra2 << " posicao: " << pos2 << endl;
    cout << palavra3 << " posicao: " << pos3 << endl;

    cout << "\nTodas as palavras devem estar na mesma posicao:" << endl;
    cout << "Palavras na posicao " << pos1 << ": ";
    for (int i = 0; i < ht.table[pos1].size(); i++) {
        cout << ht.table[pos1][i] << " ";
    }
    cout << endl;

    // Imprimindo as posições de cada palavra no vetor da tabela
    cout << "\nPosicoes das palavras na tabela:" << endl;
    for (int i = 0; i < ht.size; i++) {
        if (!ht.table[i].empty()) {
            cout << "Posicao " << i << ": ";
            for (int j = 0; j < ht.table[i].size(); j++) {
                cout << ht.table[i][j] << " (indice " << j << ") ";
            }
            cout << endl;
        }
    }

    // Teste de remocao
    cout << "\nTeste de remocao:" << endl;
    cout << "Removendo '" << palavra1 << "'..." << endl;
    string removed = ht.remove(palavra1);
    cout << "Removido: " << removed << endl;
    cout << palavra1 << " encontrado? " << (ht.find(palavra1) != -1 ? "Sim" : "Nao") << endl;

    cout << "Removendo '" << palavra2 << "'..." << endl;
    removed = ht.remove(palavra2);
    cout << "Removido: " << removed << endl;
    cout << palavra2 << " encontrado? " << (ht.find(palavra2) != -1 ? "Sim" : "Nao") << endl;

    cout << "Removendo '" << palavra3 << "'..." << endl;
    removed = ht.remove(palavra3);
    cout << "Removido: " << removed << endl;
    cout << palavra3 << " encontrado? " << (ht.find(palavra3) != -1 ? "Sim" : "Nao") << endl;

    // Teste de tamanho
    cout << "\nTeste de tamanho:" << endl;
    cout << "Tamanho atual: " << ht.getCurrentSize() << endl;

    string a1 = "abcd";
    string a2 = "bcde";

    ht.insert(a1);
    ht.insert(a2);

    cout << "\nPosicoes das palavras na tabela:" << endl;
    for (int i = 0; i < ht.size; i++) {
        if (!ht.table[i].empty()) {
            cout << "Posicao " << i << ": ";
            for (int j = 0; j < ht.table[i].size(); j++) {
                cout << ht.table[i][j] << " (indice " << j << ") ";
            }
            cout << endl;
        }
    }


    // Teste de limpeza
    cout << "\nTeste de limpeza:" << endl;
    ht.clean();
    cout << "Tabela limpa." << endl;
    cout << "Tamanho apos limpeza: " << ht.getCurrentSize() << endl;

    cout << palavra1 << " encontrado? " << (ht.find(palavra1) != -1 ? "Sim" : "Nao") << endl;
    cout << palavra2 << " encontrado? " << (ht.find(palavra2) != -1 ? "Sim" : "Nao") << endl;
}

int main() {
    runTests();
    return 0;
}