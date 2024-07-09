#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
#define UNVISITED 0
#define VISITED 1

struct element{
    int parent, distance;
    element(int p, int d): parent(p), distance(d){}
};

class Graph{
private:
    unordered_map<int,vector<pair<int,int>>> adjList;
    unordered_map<int,int> mark;
    int numEdges, numNodes;

    int n(){return numNodes;}
    int e(){return numEdges;}

public:
    Graph(int N): numEdges(0), numNodes(N) {
        for(int i = 0; i < N; i++){
            adjList[i]; mark[i] = UNVISITED;
        }
    }

    void setEdge(int i, int j, int wt){
        adjList[i].emplace_back(j,wt);
        numEdges++;
    }

    void dijkstra(int s,int D[]){
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> H;
        int P[numNodes] = {-1};
        int p,v;

        for(int i = 0; i < numNodes; i++){
            D[i] = INF; mark[i] = UNVISITED;
        }

        H.push({s,{s,0}}); D[s] = 0; 
        
        for(int i = 0; i < numNodes; i++){
        do {
                if (H.empty()) return;
                auto top = H.top(); H.pop();
                p = top.second.first;
                v = top.second.second;
            } while (mark[v] == VISITED);

            mark[v] = VISITED; P[v] = p;
            if (v == -1) return;

            for(auto& neighbor : adjList[v]){
                int w = neighbor.first;
                int weigth = neighbor.second;
                if(mark[w] != VISITED && D[w] > D[v] + weigth){
                    D[w] = D[v] + weigth;
                }
            }                
            
        }
    }


};



