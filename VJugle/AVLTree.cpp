#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int key, height, rank;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k) : key(k), height(1), rank(1), left(nullptr), right(nullptr) {}
};

class AVL {
private:
    AVLNode* root;
    int nodeCount;

    void updateRank(AVLNode* rt) {
        rt->rank = 1;
        if (rt->left != nullptr) {
            rt->rank += rt->left->rank;
        }
        if (rt->right != nullptr) {
            rt->rank += rt->right->rank;
        }
    }

    int findHelp(AVLNode* rt, int k) {
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

    int getBalance(AVLNode* rt) {
        if (rt == nullptr) { return 0; }
        return height(rt->left) - height(rt->right);
    }

    int height(AVLNode* rt) {
        if (rt == nullptr) { return 0; }
        return rt->height;
    }
    
    AVLNode* insertHelp(AVLNode* rt, int k) {
        if (rt == nullptr) {
            return new AVLNode(k);
        }
        if (rt->key > k) {
            rt->left = insertHelp(rt->left, k);
        } else {
            rt->right = insertHelp(rt->right, k);
        }

        updateRank(rt);

        rt->height = 1 + max(height(rt->left), height(rt->right));
        int balance = getBalance(rt);

        if (balance < -1 && k >= rt->right->key) {
            return leftRotate(rt);
        }
        if (balance > 1 && k < rt->left->key) {
            return rightRotate(rt);
        }
        if (balance > 1 && k >= rt->left->key) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && k < rt->right->key) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    AVLNode* removeHelp(AVLNode* rt, int k) {
        if (rt == nullptr) {
            return nullptr;
        }
        if (rt->key > k) {
            rt->left = removeHelp(rt->left, k);
        } else if (rt->key < k) {
            rt->right = removeHelp(rt->right, k);
        } else {
            if (rt->left == nullptr) {
                AVLNode* temp = rt->right;
                delete rt;
                return temp;
            } else if (rt->right == nullptr) {
                AVLNode* temp = rt->left;
                delete rt;
                return temp;
            } else {
                AVLNode* temp = getMin(rt->right);
                rt->key = temp->key;
                rt->right = removeHelp(rt->right, temp->key);
            }
        }
        
        if (rt == nullptr) return rt;
        
        rt->height = 1 + max(height(rt->left), height(rt->right));
        updateRank(rt);

        int balance = getBalance(rt);

        if (balance > 1 && getBalance(rt->left) >= 0) {
            return rightRotate(rt);
        }
        if (balance > 1 && getBalance(rt->left) < 0) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && getBalance(rt->right) <= 0) {
            return leftRotate(rt);
        }
        if (balance < -1 && getBalance(rt->right) > 0) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }
        return rt;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        updateRank(y);
        updateRank(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        updateRank(x);
        updateRank(y);

        return y;
    }

    AVLNode* getMin(AVLNode* rt) {
        if (rt == nullptr) { return nullptr; }

        while (rt->left != nullptr) {
            rt = rt->left;
        }
        return rt;
    }

    AVLNode* deleteMin(AVLNode* rt) {
        if (rt->left == nullptr) {
            return rt->right;
        }
        rt->left = deleteMin(rt->left);
        return rt;
    }

public:
    AVL() : root(nullptr), nodeCount(0) {}

    int find(int k) {
        return findHelp(root, k);
    }
    
    void insert(int k) { 
        root = insertHelp(root, k);
        nodeCount++;
    }

    void remove(int k) {
        int temp = find(k);
        if (temp != -1) {
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

    int findIndex(int k) {
        return findIndex(root, k);
    }

    int findIndex(AVLNode* rt, int k, int rankAtual = 1) {
        if (rt == nullptr) {
            return -1;
        }

        if (k < rt->key) {
            return findIndex(rt->left, k, rankAtual);
        } else if (k > rt->key) {
            int rankEsquerda = (rt->left != nullptr) ? rt->left->rank : 0;
            rankAtual += rankEsquerda + 1;
            return findIndex(rt->right, k, rankAtual); 
        } else {
            return rankAtual + ((rt->left != nullptr) ? rt->left->rank : 0);
        }
    }

    int getSize(AVLNode* rt) {
        if (rt == nullptr) return 0;
        return 1 + getSize(rt->left) + getSize(rt->right);
    }
};

int main() {
    AVL tree;

    int Q; cin >> Q;

    while (Q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            tree.insert(x);
        } else {
            int index = tree.findIndex(x);
            if (index == -1) {
                cout << "Data tidak ada" << endl;
            } else {
                cout << index << endl;
            }
        }
    }
}