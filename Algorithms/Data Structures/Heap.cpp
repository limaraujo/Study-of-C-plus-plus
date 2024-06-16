#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int size;

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Encontra o menor elemento entre o nó atual e seus filhos
        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        // Se o menor elemento não for o próprio nó, faz a troca e continua heapify
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    MinHeap(vector<int>& array) {
        heap = array;
        size = heap.size();

        // Constrói a heap bottom-up
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Remove o elemento mínimo da heap
    int removeMin() {
        if (size == 0)
            return -1; // Heap vazia

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        return root;
    }

    // Retorna verdadeiro se a heap estiver vazia
    bool isEmpty() {
        return size == 0;
    }

    // Imprime os elementos da heap após o processo de heapify
    void printHeap() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

void heapSort(vector<int>& array) {
    int n = array.size();

    // Constrói a heap mínima
    MinHeap minHeap(array);

    // Remove repetidamente o mínimo da heap e coloca no array ordenado
    for (int i = n - 1; i >= 0; i--) {
        array[i] = minHeap.removeMin();
    }
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        vector<int> array(n);

        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        // Imprime a heap após o processo de heapify
        MinHeap minHeap(array);
        minHeap.printHeap();

        // Imprime a heap após as remoções de mínimo
        while (!minHeap.isEmpty()) {
            minHeap.removeMin();
            minHeap.printHeap();
        }

        // Ordena o array usando heapsort e imprime o array ordenado
        heapSort(array);
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
