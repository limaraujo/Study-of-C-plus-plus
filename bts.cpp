#include <bits/stdc++.h>
using namespace std;

typedef struct BTSNode {
    int key;
    BTSNode* left;
    BTSNode* right;
    BTSNode(int e) : key(e), left(nullptr), right(nullptr) {}
} BTSNode;

class BTS {
private:
    BTSNode* root;
    int nodeCount;

    int findHelp(BTSNode* rt, int k) {
        if (rt == nullptr) {
            return -1;
        }

        if (rt->key > k) {
            return findHelp(rt->left, k);
        } else if (rt->key == k) {
            return rt->key;
        } else {
            return findHelp(rt->right, k);
        }
    }


    BTSNode* insertHelp(BTSNode* rt, int k) {
        if (rt == nullptr) {
            return new BTSNode(k);
        }

        if (rt->key > k) {
            rt->left = insertHelp(rt->left, k);
        } else {
            rt->right = insertHelp(rt->right, k);
        }
        
        return rt;
    }


    BTSNode* removeHelp(BTSNode* rt, int k) {
        if (rt == nullptr) {
            return nullptr;
        }
        if (rt->key > k) {
            rt->left = removeHelp(rt->left, k);
        } else if (rt->key < k) {
            rt->right = removeHelp(rt->right, k);
        } else {
            if (rt->left == nullptr) {
                return rt->right;
            } else if (rt->right == nullptr) {
                return rt->left;
            } else {
                BTSNode* temp = getMin(rt->right);
                rt->key = temp->key;
                rt->right = deleteMin(rt->right);
            }
        }
        return rt;
    }

    BTSNode* getMin(BTSNode* rt) {
        if(rt == nullptr){return nullptr;}

        while (rt->left != nullptr){
            rt = rt->left;
        }
        return rt;
    }

    BTSNode* deleteMin(BTSNode* rt) {
        if (rt->left == nullptr) {
            return rt->right;
        }
        rt->left = deleteMin(rt->left);
        return rt;
    }

    void preOrdemHelp(BTSNode* rt){
        if(rt != nullptr){
            cout << " " << rt->key;
            preOrdemHelp(rt->left);
            preOrdemHelp(rt->right);      
        }
    }

    void inOrdemHelp(BTSNode* rt){
        if(rt != nullptr){
            inOrdemHelp(rt->left);
            cout << " " << rt->key ;
            inOrdemHelp(rt->right);      
        }
    }

    void posOrdemHelp(BTSNode* rt){
        if(rt != nullptr){
            posOrdemHelp(rt->left);
            posOrdemHelp(rt->right);
            cout << " " << rt->key;      
        }
    }

public:
    BTS() : root(nullptr), nodeCount(0) {}

    int find(int k){ 
        return findHelp(root, k);
    }

    void insert(int k){ 
        root = insertHelp(root, k);
        nodeCount++;
    }

    int remove(int k){
        int temp = find(k);
        if(temp != -1){
            root = removeHelp(root, k);
            nodeCount--;
        }
        return temp;
    }

    void preOrdem(){
        preOrdemHelp(root);
        cout << endl;
    }

    void inOrdem(){
        inOrdemHelp(root);
        cout << endl;
    }

    void postOrdem(){
        posOrdemHelp(root);
        cout << endl;
    }
};

int main() {
    BTS tree; 
    int n, element; cin >> n;

    for (int i = 0; i < n; i++){
        cin >> element;
        tree.insert(element);
    }

    cout << "Pre order :";
    tree.preOrdem(); 

    cout << "In order  :";
    tree.inOrdem();   

    cout << "Post order:";
    tree.postOrdem();  

    return 0;
}
