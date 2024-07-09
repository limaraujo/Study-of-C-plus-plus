#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<vector<int>> matrix;
    vector<int>mark;
    int numEdge;
    
    int n() {return matrix.size();}
    int e() {return numEdge;}
public:
    Graph(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n, 0)); 
        mark = vector<int>(n, 0);                          
        numEdge = 0;                                        
    }

    int first(int v){
        for (int i = 0; i < n(); i++){
            if(matrix[v][i] != 0) return i;
        }
        return n();
    }

    int next(int v, int w){
        for (int i = w +1; i < n(); i++){
            if(matrix[v][i] != 0) return i;
        }
        return n();
    }

    void setEdge(int i, int j, int wt){
        if(wt == 0) {return;}
        if(matrix[i][j] == 0){
            numEdge++;
            matrix[i][j] = wt;
            matrix[j][i] = wt;
        }
    }
    
    void delEdge(int i, int j){
        if(matrix[i][j] != 0){
            numEdge--;
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }
    }

    bool isEdge(int i, int j) {
        return (matrix[i][j] != 0) ? 1 : 0;
    }

    int weigth(int i, int j){
        return matrix[i][j];
    }

    void setMark(int v, int val){
        mark[v] = val;
    }

    int getMark(int v) {
        return mark[v];
    }



};