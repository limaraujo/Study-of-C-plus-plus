#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void preOrder(vector<int>& result) const {
        preOrder(root, result);
    }

    void inOrder(vector<int>& result) const {
        inOrder(root, result);
    }

    void postOrder(vector<int>& result) const {
        postOrder(root, result);
    }

private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void preOrder(Node* node, vector<int>& result) const {
        if (node != nullptr) {
            result.push_back(node->value);
            preOrder(node->left, result);
            preOrder(node->right, result);
        }
    }

    void inOrder(Node* node, vector<int>& result) const {
        if (node != nullptr) {
            inOrder(node->left, result);
            result.push_back(node->value);
            inOrder(node->right, result);
        }
    }

    void postOrder(Node* node, vector<int>& result) const {
        if (node != nullptr) {
            postOrder(node->left, result);
            postOrder(node->right, result);
            result.push_back(node->value);
        }
    }
};

void processCase(int caseNumber, const vector<int>& numbers) {
    BinarySearchTree bst;
    for (int num : numbers) {
        bst.insert(num);
    }

    vector<int> preOrderResult, inOrderResult, postOrderResult;

    bst.preOrder(preOrderResult);
    bst.inOrder(inOrderResult);
    bst.postOrder(postOrderResult);

    cout << "Case " << caseNumber << ":\n";
    
    cout << "Pre.: ";
    for (size_t i = 0; i < preOrderResult.size(); ++i) {
        if (i > 0) cout << " ";
        cout << preOrderResult[i];
    }
    cout << "\n";

    cout << "In..: ";
    for (size_t i = 0; i < inOrderResult.size(); ++i) {
        if (i > 0) cout << " ";
        cout << inOrderResult[i];
    }
    cout << "\n";

    cout << "Post: ";
    for (size_t i = 0; i < postOrderResult.size(); ++i) {
        if (i > 0) cout << " ";
        cout << postOrderResult[i];
    }
    cout << "\n";
}

// Função principal
int main() {
    int c;
    cin >> c;

    for (int i = 1; i <= c; ++i) {
        int n;
        cin >> n;
        vector<int> numbers(n);
        for (int j = 0; j < n; ++j) {
            cin >> numbers[j];
        }
        processCase(i, numbers);
    }

    return 0;
}
