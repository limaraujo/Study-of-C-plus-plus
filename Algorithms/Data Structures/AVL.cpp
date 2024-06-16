#include <bits/stdc++.h>
using namespace std;

struct AVLNode{
    int key, height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k): key(k), height(0), left(nullptr), right(nullptr) {}
};

class AVL{
private:
    AVLNode* root;
    int nodeCount;

    int findHelp(AVLNode* rt, int k){
        if(rt ==  nullptr){
            return -1;
        }

        if(rt->key > k){
            return findHelp(rt->left, k);
        }else if(rt->key == k){
            return rt->key;
        }else{
            return findHelp(rt->right, k);
        }
    }

    int getBalance(AVLNode* rt){
        if(rt == nullptr){return 0;}
        return height(rt->left) - height(rt->right);
    }

    int height(AVLNode* rt){
        if(rt == nullptr){return -1;}
        return rt->height;
    }
    
    AVLNode* insertHelp(AVLNode* rt, int k){
        if(rt == nullptr){
            return new AVLNode(k);
        }
        if(rt->key > k){
            rt->left = insertHelp(rt->left, k);
        }else{
            rt->right = insertHelp(rt->right, k);
        }

        rt->height = 1 + max(height(rt->left), height(rt->right));
        int balance = getBalance(rt);

        if (balance < -1 && k > rt->right->key){
            return leftRotate(rt);
        }
        if (balance > 1 && k < rt->left->key){
            return rightRotate(rt);
        }
        if (balance > 1 && k > rt->left->key){
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && k < rt->right->key){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    AVLNode* removeHelp(AVLNode* rt, int k){
        if(rt == nullptr){
            return nullptr;
        }
        if(rt->key > k){
            rt->left = removeHelp(rt->left,k);
        }else if(rt->key < k){
            rt->right = removeHelp(rt->right,k);
        }else{
            if(rt->left == nullptr){
                AVLNode* temp = rt->right;
                delete rt;
                return temp;
            }else if(rt->right == nullptr){
                AVLNode* temp = rt->left;
                delete rt;
                return temp;
            }else{
                AVLNode* temp = getMin(rt->right);
                rt->key = temp->key;
                rt->right = removeHelp(rt->right, temp->key);
            }
        }
        
        if(rt == nullptr) return rt;
        
        rt->height = 1 + max(height(rt->left), height(rt->right));
        int balance = getBalance(rt);

        if (balance > 1 && getBalance(rt->left) >= 0){
            return rightRotate(rt);
        }
        if (balance > 1 && getBalance(rt->left) < 0){
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && getBalance(rt->right) <= 0){
            return leftRotate(rt);
        }
        if (balance < -1 && getBalance(rt->right) > 0){
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    AVLNode* rightRotate(AVLNode* y){
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x){
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode* getMin(AVLNode* rt){
        if(rt == nullptr){return nullptr;}

        while (rt->left != nullptr){
            rt = rt->left;
        }
        return rt;
    }

    AVLNode* deleteMin(AVLNode* rt){
        if(rt->left == nullptr){
            return rt->right;
        }
        rt->left = deleteMin(rt->left);
        return rt;
    }

public:
    AVL() : root(nullptr), nodeCount(0) {}

    int find(int k){
        return findHelp(root, k);
    }
    
    void insert(int k){ 
        root = insertHelp(root, k);
        nodeCount++;
    }

    void remove(int k){
        int temp = find(k);
        if(temp != -1){
            root = removeHelp(root, k);
            nodeCount--;
        }
    }

    void inOrder(AVLNode* rt) {
        if (rt == nullptr) return;
        inOrder(rt->left);
        cout << rt->key << " ";
        inOrder(rt->right);
    }

    void printInOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    AVL tree;

    // Inserindo elementos
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "Árvore em ordem após inserções: ";
    tree.printInOrder(); // Esperado: 10 20 25 30 40 50

    // Removendo elementos
    tree.remove(40);
    cout << "Árvore em ordem após remover 40: ";
    tree.printInOrder(); // Esperado: 10 20 25 30 50

    tree.remove(25);
    cout << "Árvore em ordem após remover 25: ";
    tree.printInOrder(); // Esperado: 10 20 30 50

    tree.remove(10);
    cout << "Árvore em ordem após remover 10: ";
    tree.printInOrder(); // Esperado: 20 30 50

    tree.insert(60);

    tree.insert(70);

    tree.insert(80);

    tree.printInOrder();

    return 0;
}
