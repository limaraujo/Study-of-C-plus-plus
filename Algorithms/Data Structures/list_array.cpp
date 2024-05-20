//array_list
#include <iostream>
#include <cstdlib>

using namespace std;

struct list_array {
    int maxSize;
    int listSize;
    int curr;
    int *listArray;

    void create_list(int size) {
        maxSize = size;
        listSize = curr = 0;
        listArray = (int*) malloc(size*sizeof(int));
    }

    void append(int it) {
        if (listSize < maxSize) {
            listArray[listSize++] = it;
        }
    }

    void print_elemento(int indice) {
        if (indice < listSize) {
            cout << listArray[indice];
        }
    }

    void print_list() {
        for (int i = 0; i < listSize; i++) {
            cout << listArray[i] << " ";
        }
        cout << endl;
    }

    void insert(int it) {
        if (listSize < maxSize && curr >= 0 && curr <= listSize) {
            for (int i = listSize; i > curr; i--) {
                listArray[i] = listArray[i - 1];
            }
            listArray[curr] = it;
            listSize++;
        }
    }

    void moveToStart() {
        curr = 0;
    }

    void moveToEnd() {
        curr = listSize - 1;
    }

    void prev() {
        if (curr > 0) {
            curr--;
        }
    }

    void next() {
        if (curr < listSize) {
            curr++;
        }
    }

    int remove() {
        if (curr < 0 || curr >= listSize) { 
            return -1;
        }

        int it = listArray[curr];
        for (int i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }

        listSize--;
        return it;
    }

    int length() {
        return listSize;
    }

    int currPoss() {
        return curr;
    }

};

int main() {
    list_array lista;
    lista.create_list(5);
    lista.append(1);
    lista.append(2);
    lista.append(3);
    lista.print_list();
    lista.moveToEnd();
    lista.append(4);
    int x = lista.length();
    cout << x << endl;
    lista.print_list();
    lista.print_elemento(3);
    lista.remove();
    lista.print_list();
    return 0;
};





