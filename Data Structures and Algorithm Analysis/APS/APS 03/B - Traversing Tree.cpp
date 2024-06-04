#include <iostream>
using namespace std;

struct BSTNode {
    int key; 
    BSTNode* left; 
    BSTNode* right;
    BSTNode(int k): key(k), left(nullptr), right(nullptr) {}
};

typedef struct binaryTreeSearch {
    BSTNode* root; 
    int nodecount;

    binaryTreeSearch() : root(nullptr), nodecount(0) {}

    int findHelp(BSTNode* rt, int k) {
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

    int find(int k) {
        return findHelp(root, k);
    }

    BSTNode* insertHelp(BSTNode* rt, int k) {
        if (rt == nullptr) {
            return new BSTNode(k);
        }

        if (rt->key > k) {
            rt->left = insertHelp(rt->left, k);
        } else {
            rt->right = insertHelp(rt->right, k);
        }
        
        return rt;
    }

    void insert(int k) {
        root = insertHelp(root, k);
        nodecount++;
    }

    void PrintPreOrder(BSTNode *rt) {
        if (rt != nullptr) {
            cout << " " << rt->key;
            PrintPreOrder(rt->left);
            PrintPreOrder(rt->right);
        }
    }

    void PreOrder(){
        cout << "Pre order :";
        PrintPreOrder(root);
        cout << "\n";
    }

    void PrintInOrder(BSTNode *rt) {
        if (rt != nullptr) {
            PrintInOrder(rt->left);
            cout << " " << rt->key;
            PrintInOrder(rt->right);
        }
    }

    void InOrder(){
        cout << "In order  :";
        PrintInOrder(root);
        cout << "\n";
    }

    void PrintPostOrder(BSTNode *rt) {
        if (rt != nullptr) {
            PrintPostOrder(rt->left);
            PrintPostOrder(rt->right);
            cout << " " << rt->key;
        }
    }

    void PostOrder(){
        cout << "Post order:";
        PrintPostOrder(root);
        cout << "\n";
    }
};

int main() {
    binaryTreeSearch Hogwarts;
    int tam = 0, elemento = 0;
    cin >> tam;

    for (int i = 0; i < tam; i++) {
        cin >> elemento;
        Hogwarts.insert(elemento);
    }

    Hogwarts.PreOrder();
    Hogwarts.InOrder();
    Hogwarts.PostOrder();

    return 0;
}
