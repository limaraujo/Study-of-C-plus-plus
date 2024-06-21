#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    int maxSize;
    int currSize;
    string* heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < currSize && heap[left] > heap[largest])
            largest = left;
        if (right < currSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapBottomUp(string H[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            int k = i;
            string v = H[k];
            bool heap = false;
            while (!heap && 2 * k + 1 < n) {
                int j = 2 * k + 1;
                if (j < n - 1 && H[j] < H[j + 1]) {
                    j++;
                }
                if (v >= H[j]) {
                    heap = true;
                } else {
                    H[k] = H[
                        j];
                    k = j;
                }
            }
            H[k] = v;
        }
    }


public:
    MaxHeap(int max) : maxSize(max+1), currSize(0) {
        heap = new string[maxSize+1];
    }

    ~MaxHeap() {
        delete[] heap;
    }

    void insert(string s) {
        if (currSize == maxSize-1) {
            cout << "Heap is full" << endl;
            return;
        }

        int i = currSize;
        heap[i] = s;
        currSize++;

        heapifyUp(i);
    }

    string remove() {
        if (currSize == 0) {
            cout << "Heap is empty" << endl;
            return "";
        }

        string removedElement = heap[0]; // Elemento a ser removido (o máximo, na raiz)
        heap[0] = heap[currSize - 1];    // Substitui a raiz com o último elemento
        currSize--;

        heapifyDown(0);  // Restaura a propriedade do heap máximo

        heapBottomUp(heap, currSize); // Reconstrói o heap usando heapBottomUp

        return removedElement; // Retorna o elemento removido
    }

    void printHeap() {
        for (int i = 1; i < currSize; ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap maxHeap(10);
    vector<string> elements = {"apple", "banana", "cherry", "date", "elderberry"};

    for (const auto& element : elements) {
        maxHeap.insert(element);
    }

    cout << "Heap after insertions:" << endl;
    maxHeap.printHeap();

    string removedElement = maxHeap.remove();
    cout << "Removed element: " << removedElement << endl;

    cout << "Heap after removal and heapBottomUp:" << endl;
    maxHeap.printHeap();

    return 0;
}
