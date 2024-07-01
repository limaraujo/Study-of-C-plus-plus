#include <bits/stdc++.h>
using namespace std;

class Graph{
private :
    vector<vector<int>> matrix;
    int numEdge;
    int* mark;
    int* pred;

    int n(){return matrix.size();}
    int e(){return numEdge;}

public :
    Graph(int n){
        matrix = vector<vector<int>>(n,vector<int>(n,0));
        numEdge = 0;
        mark = (int*)malloc(n * sizeof(int));
        memset(mark, 0, n * sizeof(int));
        pred = (int*)malloc(n * sizeof(int));
        memset(pred, -1, n * sizeof(int));
    };

    int first(int v){
        for(int i = 0; i < n(); i++){
            if(matrix[v][i] != 0) return i;
        }
        return n();
    }

    int next(int v, int w) {
        for (int i = w + 1; i <= n() - 1; i++) {
            if (matrix[v][i] != 0) {
                return i;
            }
        }
        return n();  // Se não houver próximo vizinho, retorna 'n'.
    }

    void setEdge(int i, int j, int wt){
        if(wt == 0){return;}
        if(matrix[i][j] == 0){
            matrix[i][j] = wt; 
            matrix[j][i] = wt; 
            numEdge++;
        }
    }

    void delEdge(int i, int j){
        if(matrix[i][j] != 0){
            matrix[i][j] = 0; 
            matrix[j][i] = 0; 
            numEdge--;        
        }
    }

    bool isEdge(int i, int j){
        return matrix[i][j] != 0 ? 1:0;
    }

    int weight(int i, int j){
        return matrix[i][j];
    }

    void setMark(int v, int val){
        mark[v] = val;
    }

    int getMark(int v){
        return mark[v];
    }

    void preVisit(int v){
        cout << "Pre Visit: " << v << endl;
    }
    
    void posVisit(int v){
        cout << "Pos Visit: " << v << endl;
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
            cout << w << endl;
            while (w < n()){
                if (getMark(w) == 0){
                    setMark(w,1);
                    pred[w] = v;
                    Q.push(w);
                }
                w = next(v,w);
            }
            posVisit(v);            
        }
    }

    void graphTraverse(){
        for(int v = 0;v < n(); v++){
            mark[v] = 0;
        }
        for(int v = 0;v < n(); v++){
            if(getMark(v) == 0)
            BFS(v);
        }
    }

    void printPred() {
        for (int i = 0; i < n(); i++) {
            cout << pred[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    // Exemplo de uso do grafo
    Graph g(6);  // Cria um grafo com 6 vértices.
    g.setEdge(0, 2, 1);
    g.setEdge(0, 4, 1);
    g.setEdge(2, 1, 1);
    g.setEdge(2, 3, 1);
    g.setEdge(2, 5, 1);
    g.setEdge(1, 5, 1);
    g.setEdge(3, 5, 1);
    g.setEdge(4, 5, 1);
    //g.setEdge(2, 0, 1);  // Estas linhas são comentadas porque adicionam arestas já definidas ou redundantes.
    //g.setEdge(2, 1, 1);
    //g.setEdge(3, 2, 1);
    //g.setEdge(4, 0, 1);
    //g.setEdge(5, 1, 1);
    //g.setEdge(5, 2, 1);
    //g.setEdge(5, 3, 1);
    //g.setEdge(5, 4, 1);
    g.graphTraverse();  // Pode ser chamado para percorrer o grafo inteiro.
    g.printPred();

    return 0;
}