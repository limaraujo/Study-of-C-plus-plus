#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    
    private:
    vector<int> heap;
    int currSize, maxSize;

    void HeapBottomUp(int H[], int n) {
        for (int i = n/2; i >= 1; i--) {
            int k = i;int v = H[k];
            bool heap = false;
            while (!heap && 2 * k <= n) {
                int j = 2 * k;
                if (j < n) {
                    if (H[j] < H[j + 1]) {
                        j = j + 1;
                    }
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

    int remove_max(int H[], int n) {
        int v = H[1];
        H[1] = H[n];
        n = n - 1;
        int k = 1;
        bool heap = false;
        while (!heap && 2 * k <= n) {
            int j = 2 * k;
            if (j < n) {
                if (H[j] < H[j + 1]) {
                    j = j + 1;
                }
            }
            if (H[k] >= H[j]) {
                heap = true;
            } else {
                int temp = H[k];
                H[k] = H[j];
                H[j] = temp;
                k = j;
            }
        }
        return v;
    }
};