#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    int currSize, maxSize;

    int parent(int i){
        return (i-1)/2;
    }
    int childLeft(int i){
        return 2*i;
    }
    int childRight(int i){
        return 2*i+1;
    }

    void heapifyDown(int i){
        int smallest = i;
        int left = childLeft(i);
        int right = childRight(i);

        if(left < currSize && heap[left] < heap[smallest])
            smallest = left;
        if(right < currSize && heap[right] < heap[smallest])
            smallest = right;
        
        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int max):maxSize(max), currSize(0){
        vector<int> heap(maxSize+1);
    }

    void insert(int key)



};
