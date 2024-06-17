#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<string> heap;
    int maxSize, currSize;

    int parent(int i) { return i / 2; }
    int childLeft(int i) { return 2 * i; }
    int childRight(int i) { return 2 * i + 1; }

    void heapifyUp(int i) {
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int top = i;
        int left = childLeft(i);
        int right = childRight(i);

        if (left <= currSize && heap[left] > heap[top])
            top = left;
        if (right <= currSize && heap[right] > heap[top])
            top = right;

        if (top != i) {
            swap(heap[i], heap[top]);
            heapifyDown(top);
        }
    }

public:
    MaxHeap(int size) {
        maxSize = size;
        currSize = 0;
        heap.resize(maxSize + 1);
    }

    void insert(string s) {
        if (currSize + 1 == maxSize) {
            return;
        }

        currSize++;
        heap[currSize] = s;
        heapifyUp(currSize);
    }

    string removeMax() {
        if (currSize == 0) {
            return "";
        }

        string removed = heap[1];
        swap(heap[1], heap[currSize]);
        currSize--;
        heapifyDown(1);
        return removed;
    }

    string getMax() {
        return heap[1];
    }
};

int main() {
    MaxHeap maxheap(2000001);  
    string s, k;
    cin >> s;
    while (s != "end") {
        if (s == "insert") {
            cin >> k;
            maxheap.insert(k);
        } else {
            k = maxheap.removeMax();
            cout << k << endl;
        }
        cin >> s;
    }

    return 0;
}
