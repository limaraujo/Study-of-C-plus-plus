#include <bits/stdc++.h>
using namespace std;

class HeapMin {
private:
    int currSize, maxSize;
    int* heap;

    int parent(int i) { return i / 2; }
    int childLeft(int i) { return i * 2; }
    int childRight(int i) { return i * 2 + 1; }

    void HeapBottomUp(int H[], int n){
        for(int i = n/2; i >= 1; i--){
            int k = i, v = H[k];
            bool heap = false;
            while(!heap && 2*k <= n){
                int j = 2*k;
                if(j < n && H[j] > H[j+1]){
                    j++;
                }if(v <= H[j]){
                    heap = true;
                }else{
                    H[k] = H[j];
                    k = j;
                }
            }
            H[k] = v;
        }
    }

    void heapifyDown(int i){
        int top = i;
        int left = childLeft(i);
        int right = childRight(i);

        if(left <= currSize && heap[left] < heap[i]){
            top = left;
        }
        if(right <= currSize && heap[right] < heap[i]){
            top = right;
        }

        if(top != i){
            swap(heap[i], heap[top]);
            heapifyDown(top);
        } 
    }

    
};

