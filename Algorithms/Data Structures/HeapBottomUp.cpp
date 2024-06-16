#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    int *heap;
    int maxSize;

    void HeapBottomUp(int H[], int n) {
        for (int i = n / 2; i >= 1; i--) {
            int k = i;
            int v = H[k];
            bool heap = false;
            while (!heap && 2 * k <= n) {
                int j = 2 * k;
                if (j < n && H[j] < H[j + 1]) {
                    j++;
                }
                if (v >= H[j]) {
                    heap = true;
                } else {
                    H[k] = H[j];
                    k = j;
                }
            }
            H[k] = v;
        }
    }

public:
    MinHeap(int size) : maxSize(size) {
        heap = new int[size + 1];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void HeapSort(int H[], int n) {
        HeapBottomUp(H, n);

        for (int i = 1; i <= n; i++) {
            cout << H[i] << " ";
        }
        cout << endl;

        for (int i = n; i >= 2; i--) {
            swap(H[1], H[i]);
            HeapBottomUp(H, i - 1);

            for (int j = 1; j <= i - 1; j++) {
                cout << H[j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        cin >> n;
        int *H = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> H[i];
        }

        MinHeap minHeap(n);
        minHeap.HeapSort(H, n);

        for (int i = 1; i <= n; i++) {
            cout << H[i] << " ";
        }
        cout << endl;

        delete[] H;
    }

    return 0;
}
