#include <bits/stdc++.h>
using namespace std;

typedef struct BTSNode{
    int key;
    int element;
    BTSNode* left;
    BTSNode* rigth;

    BTSNode(int k, int e): key(k), element(e), left(nullptr), rigth(nullptr){}
};

typedef struct BTS{
    BTSNode* root;
    int nodecout;

    BTS() : root(nullptr),  nodecout(0){}

    int findHelp(BTSNode& rt, int K){
        if()
    }
};

