#include <iostream>
#include <algorithm>
using namespace std;

class HeapMin {
private:
    int currSize, maxSize;
    int* heap;

    int parent(int i) { return i / 2; }
    int childLeft(int i) { return i * 2; }
    int childRight(int i) { return i * 2 + 1; }

    void heapifyDown(int i) {
        int top = i;
        int left = childLeft(i);
        int right = childRight(i);

        if (left <= currSize && heap[left] < heap[top]) {
            top = left;
        }
        if (right <= currSize && heap[right] < heap[top]) {
            top = right;
        }

        if (top != i) {
            swap(heap[top], heap[i]);
            heapifyDown(top);
        }
    }

public:
    HeapMin(int size) : currSize(0), maxSize(size) {
        heap = new int[size + 1];
    }

    ~HeapMin() {
        delete[] heap;
    }

    void insert(int value) {
        if (currSize >= maxSize) {
            return;
        }

        currSize++;
        heap[currSize] = value;
        int i = currSize;

        while (i > 1 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int removeMin() {
        if (currSize == 0) {
            return -1;
        }

        int min = heap[1];
        heap[1] = heap[currSize];
        currSize--;
        heapifyDown(1);
        return min;
    }

    int size(){
        return currSize;
    }
};

int main() {
    int length;
    cin >> length;

    while (length != 0) {
        HeapMin Hogwarts(length + 1);
        int sum_pesos[length +1];

        for (int i = 0; i < length; i++) {
            int value;
            cin >> value;
            Hogwarts.insert(value);
        }

        for (int i = 0; i < length && Hogwarts.size() > 0; i++){
            int x1 = Hogwarts.removeMin();
            int x2 = Hogwarts.removeMin();
            int sum = x1 + x2;
            sum_pesos += sum;
        }

        cout << sum_pesos << endl;
        cin >> length;
    }

    return 0;
}
