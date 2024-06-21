//HeapTopBottom

#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    private:
        string *heap;
        int maxSize, currSize;

        int parent(int i){return i/2;}
        int childLeft(int i){return 2*i;}
        int childRight(int i){return 2*i+1;}

        void heapifyUp(int i){
            while(i != 1 && heap[parent(i)] < heap[i]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void heapifyDown(int i){
            int largest = i;
            int left = childLeft(i);
            int right = childRight(i);

            if(left <= currSize && heap[left] > heap[largest])
                largest = left;
            if(right <= currSize && heap[right] > heap[largest])
                largest = right;

            if(largest != i){
                swap(heap[i], heap[largest]);
                heapifyDown(largest);
            }
        }

        void heapBottomUp(string H[], int n){
            for(int i = n/2; i >= 1; i--){
                int k = i;
                string v = H[k];
                bool heap = false;
                while(!heap && 2*k <= n){
                    int j = 2*k;
                    if(j < n && H[j] < H[j+1]){
                        j++;
                    }
                    if(v >= H[j]){
                        heap = true;
                    }else{
                        H[k] = H[j];
                        k = j;
                    }
                }
                H[k] = v;
            }
        }

    public:
        MaxHeap(int size){
            maxSize = size;
            currSize = 0;
            heap = new string[size+1];
        }

        ~MaxHeap(){
            delete[] heap;
        }

        void insert(string value){
            if(currSize+1 == maxSize){
                cout << "Tamanho máximo atingido!" << endl;
                return;
            }

            currSize++;
            heap[currSize] = value;
            heapifyUp(currSize);
        }

        void print(){
            for(int i = 1; i <= currSize; i++){
                cout << heap[i] << " ";
            }
            cout << endl;
        }

        string removeMax(){
            if(currSize == 0){
                return "";
            }

            string max = heap[1];
            heap[1] = heap[currSize];
            currSize--;
            heapifyDown(1);
            heapBottomUp(heap, currSize);
            return max;
        }

        string getMax(){
            if(currSize == 0){
                cout << "Não há elemento no topo." << endl;
                return "";
            }

            return heap[1];
        }
};

int main() {
    MaxHeap maxheap(2000001);  
    string s, k;
    cin >>s;
    while (s != "end") {
        if (s == "insert") {
            cin >> k;
            maxheap.insert(k);
        } else{
            k = maxheap.removeMax();
            cout << k << endl;
        }
        cin>>s;
    }

    return 0;
}