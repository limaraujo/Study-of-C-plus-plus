#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<string> heap;
    int currSize;

    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void heapifyUp(int i) {
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left <= currSize && heap[left] > heap[largest])
            largest = left;
        if (right <= currSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap(int size) {
        heap.resize(size + 1);
        currSize = 0;
    }

    void insert(string value) {
        if (currSize + 1 >= heap.size()) {
            return;
        }

        currSize++;
        heap[currSize] = value;
        heapifyUp(currSize);
    }

    string removeMax() {
        if (currSize == 0) {
            return "";
        }

        string max = heap[1];
        heap[1] = heap[currSize];
        currSize--;
        heapifyDown(1);
        return max;
    }

    string getMax() {
        if (currSize == 0) {
            return "";
        }

        return heap[1];
    }

    void printHeap() {
        for (int i = 1; i <= currSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
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
