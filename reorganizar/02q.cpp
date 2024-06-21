//heap
#include <bits/stdc++.h>
using namespace std;

class HeapMin {
private:
    int currSize, maxSize;
    int* heap;

    int parent(int i) { return i / 2; }
    int childLeft(int i) { return i * 2; }
    int childRight(int i) { return i * 2 + 1; }

    void HeapBottomUp(int H[], int n) {
        for (int i = n / 2; i >= 1; i--) {
            int k = i, v = H[k];
            bool heap = false;
            while (!heap && 2 * k <= n) {
                int j = 2 * k;
                if (j < n && H[j] > H[j + 1])j++;
                if (v <= H[j]) {
                    heap = true;
                } else {
                    H[k] = H[j];
                    k = j;
                }
            }
            H[k] = v;
        }
    }

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

    void insert(int value) {
        if (currSize >= maxSize) {return;}

        currSize++;
        heap[currSize] = value;
        int i = currSize;

        while (i > 1 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int removeMin() {
        if (currSize == 0) {return -1;}

        int min = heap[1];
        heap[1] = heap[currSize];
        currSize--;
        //heapifyDown(1);
        HeapBottomUp(heap, currSize);
        return min;
    }

};

int main() {
    int length;
    cin >> length;

    while (length != 0) {
        HeapMin Hogwarts(length + 1);
        int sum_pesos[length]{0};
        int x1 = 0, x2 = 0;

        for (int i = 0; i < length; i++) {
            int value;
            cin >> value;
            Hogwarts.insert(value);
        }

        for (int i = 0; i < length - 1; i++) {
            int severus = Hogwarts.removeMin();
            int snape = Hogwarts.removeMin();
            x1 = severus + snape;
            Hogwarts.insert(x1);
            sum_pesos[i] = x1;
        }

        for (int i = 0; i < length - 1; i++) {
            x2 += sum_pesos[i];
        }

        cout << x2 << endl;
        cin >> length;
    }

    return 0;
}
