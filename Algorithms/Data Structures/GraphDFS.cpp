#include <bits/stdc++.h>  // Inclui todas as bibliotecas padrão do C++.
using namespace std;

class Graph {
private:
    vector<vector<int>> matrix;  // Matriz de adjacência.
    vector<int> mark;            // Vetor de marcação para controlar os vértices visitados.
    vector<int> pred;
    int numEdge;                 // Contador de arestas.

    int n() { return matrix.size(); }  // Retorna o número de vértices.
    int e() { return numEdge; }        // Retorna o número de arestas.

public:
    // Inicializa o grafo com 'n' vértices.
    Graph(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n, 0)); // Cria a matriz de adjacência com zeros.
        mark = vector<int>(n, 0);                          // Inicializa todas as marcações com 0 (não visitado).
        pred = vector<int>(n, -1);                          // Inicializa todas as marcações com 0 (não visitado).
        numEdge = 0;                                        // Inicializa o contador de arestas com 0.
    }

    // Retorna o primeiro vizinho de 'v'.
    int first(int v) {
        for (int i = 0; i <= n() - 1; i++) {
            if (matrix[v][i] != 0) {
                return i;
                
            }
        }
        return n();  // Se não houver vizinho, retorna 'n'.
    }

    // Retorna o próximo vizinho de 'v' após 'w'.
    int next(int v, int w) {
        for (int i = w + 1; i <= n() - 1; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return n();  // Se não houver próximo vizinho, retorna 'n'.
    }

    // Define uma aresta entre os vértices 'i' e 'j' com peso 'wt'.
    void setEdge(int i, int j, int wt) {
        if (wt == 0) return;
        if (matrix[i][j] == 0) {
            numEdge++;
            matrix[i][j] = wt;
            matrix[j][i] = wt; // Para grafos não direcionados.
        }
    }

    // Remove a aresta entre os vértices 'i' e 'j'.
    void delEdge(int i, int j) {
        if (matrix[i][j] != 0) {
            numEdge--;
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }

    // Verifica se há uma aresta entre 'i' e 'j'.
    bool isEdge(int i, int j) {
        return matrix[i][j] != 0;
    }

    // Retorna o peso da aresta entre 'i' e 'j'.
    int weight(int i, int j) {
        return matrix[i][j];
    }

    // Define a marcação do vértice 'v' com o valor 'val'.
    void setMark(int v, int val) {
        mark[v] = val;
    }

    // Retorna a marcação do vértice 'v'.
    int getMark(int v) {
        return mark[v];
    }

    // Função chamada antes de visitar os vizinhos de 'v'.
    void preVisit(int v) {
        cout << v << " ";
    }

    // Função chamada após visitar todos os vizinhos de 'v'.
    void postVisit(int v) {
        cout << "Post-visit: " << v << endl;
    }

    // Implementa a busca em profundidade (DFS) a partir do vértice 'v'.
    void DFS(int v) {
        preVisit(v);
        setMark(v, 1);  // Marca 'v' como visitado.
        int w = first(v);
        while (w < n()) {  // Percorre todos os vizinhos de 'v'.
            if (getMark(w) == 0) {
                DFS(w);  // Chama recursivamente DFS para 'w' se não foi visitado.
            }
            w = next(v, w);  // Pega o próximo vizinho de 'v'.
        }
        //postVisit(v);
    }

    // Percorre todo o grafo, chamando DFS para cada componente conectado.
    void graphTraverseDFS(int i) {
        for (int v = 0; v < n(); v++) {
            setMark(v, 0);  // Marca todos os vértices como não visitados.
        }
        //for (int v = 0; v < n(); v++) {
        //    if (getMark(v) == 0) {
        //      DFS(v);  // Chama DFS para cada vértice não visitado.
        //    }}
        DFS(i);
        cout << endl;
    }

    void BFS(int v){
        queue <int>  Q;
        Q.push(v);
        setMark(v, 1);
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            preVisit(v);
            int w = first(v);
            while (w < n()){
                if (getMark(w) == 0){
                    setMark(w,1);
                    Q.push(w);
                }
                w = next(v,w);
            }
        }
    }

    void graphTraverseBFS(int i){
        for(int v = 0;v < n(); v++){
            mark[v] = 0;
        }
        BFS(i);
        cout << endl;
    }

    void printPred(){
        for(auto i : pred){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, q, i, j; string op;
    cin >> n >> q;
    Graph Hogwarts(n);
    
    while (q--){
        cin >> op;
        if(op == "add"){
            cin >> i >> j;
            Hogwarts.setEdge(i,j,1);
        }else if(op == "BFS"){
            cin >> i;
            Hogwarts.graphTraverseBFS(i);
            cout<< "Predecessores" << endl;
            Hogwarts.printPred();
        }else if(op == "DFS"){
            cin >> i;
            Hogwarts.graphTraverseDFS(i);
        }
    }

    return 0;  
}
