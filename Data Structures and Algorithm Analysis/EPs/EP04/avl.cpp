#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int key, height;
    AVLNode* right;
    AVLNode* left;

    AVLNode(int k) : key(k), height(1), right(nullptr), left(nullptr) {}
};

class AVL {
private:
    AVLNode* root;
    int nodeCount;

    int getBalance(AVLNode* rt) {
        if (rt == nullptr) return 0;
        return h(rt->left) - h(rt->right);
    }

    int h(AVLNode* rt) {
        if (rt == nullptr) return 0;
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

        rt->height = 1 + max(h(rt->left), h(rt->right));
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

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;

        return y;
    }

    AVLNode* getMin(AVLNode* rt) {
        if (rt == nullptr) return nullptr;

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

    void preOrder(AVLNode* rt) {
        if (rt == nullptr) return;
        cout << rt->key << endl;
        preOrder(rt->left);
        preOrder(rt->right);
    }

public:
    AVL() : root(nullptr), nodeCount(0) {}
    void insert(int k) {
        root = insertHelp(root, k);
        nodeCount++;
    }

    void printPreOrder() {
        preOrder(root);
        cout << "END" << endl;
    }
};

int main() {
    int c, n, Palestra;
    cin >> c;
    while (c--) {
        cin >> n;
        AVL AbelFerreira; 

        for (int i = 0; i < n; i++) {
            cin >> Palestra;
            AbelFerreira.insert(Palestra);
        }
        AbelFerreira.printPreOrder();
    }
    return 0;
}
