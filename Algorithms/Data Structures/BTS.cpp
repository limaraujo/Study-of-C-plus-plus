#include <bits/stdc++.h>
using namespace std;

struct BTSNode {
    int key;
    int element;
    BTSNode* left;
    BTSNode* right;

    BTSNode(int k, int e): key(k), element(e), left(nullptr), right(nullptr) {}
};

struct BTS {
    BTSNode* root;
    int nodecount;

    BTS() : root(nullptr), nodecount(0) {}

    int findHelp(BTSNode* rt, int k) {
        if (rt == nullptr) {
            return -1;
        }
        if (rt->key > k) {
            return findHelp(rt->left, k);
        } else if (rt->key == k) {
            return rt->element;
        } else {
            return findHelp(rt->right, k);
        }
    }

    int find(int k) {
        return findHelp(root, k);
    }

    BTSNode* insertHelp(BTSNode* rt, int k, int e) {
        if (rt == nullptr) {
            return new BTSNode(k, e);
        }
        if (k > rt->key) {
            rt->right = insertHelp(rt->right, k, e);
        } else if (k < rt->key) {
            rt->left = insertHelp(rt->left, k, e);
        }
        return rt;
    }

    void insert(int k, int e) {
        root = insertHelp(root, k, e);
        nodecount++;
    }

    BTSNode* getMin(BTSNode* rt) {
        if (rt->left == nullptr) {
            return rt;
        }
        return getMin(rt->left);
    }

    BTSNode* deleteMin(BTSNode* rt) {
        if (rt->left == nullptr) {
            return rt->right;
        }
        rt->left = deleteMin(rt->left);
        return rt;
    }

    int remove(int k) {
        int temp = findHelp(root, k);
        if (temp != -1) {
            root = removeHelp(root, k);
            nodecount--;
        }
        return temp;
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
                rt->element = temp->element;
                rt->key = temp->key;
                rt->right = removeHelp(rt->right, temp->key);
            }
        }
        return rt;
    }
};

int main() {
    // Create an instance of BTS
    BTS tree;

    // Insert elements into the tree
    tree.insert(5, 50);
    tree.insert(3, 30);
    tree.insert(7, 70);
    tree.insert(2, 20);
    tree.insert(4, 40);
    tree.insert(6, 60);
    tree.insert(8, 80);

    // Find elements
    cout << "Find key 5: " << tree.find(5) << endl; // Output: 50
    cout << "Find key 3: " << tree.find(3) << endl; // Output: 30
    cout << "Find key 7: " << tree.find(7) << endl; // Output: 70
    cout << "Find key 10: " << tree.find(10) << endl; // Output: -1 (not found)

    // Remove elements
    cout << "Remove key 3: " << tree.remove(3) << endl; // Output: 30 (element removed)
    cout << "Remove key 5: " << tree.remove(5) << endl; // Output: 50 (element removed)
    cout << "Remove key 10: " << tree.remove(10) << endl; // Output: -1 (not found)

    // Try finding removed elements
    cout << "Find key 3: " << tree.find(3) << endl; // Output: -1 (not found)
    cout << "Find key 5: " << tree.find(5) << endl; // Output: -1 (not found)

    return 0;
}