#include <bits/stdc++.h>
using namespace std;

typedef struct Link{
    int element;
    Link* next;
    Link(int it): element(it), next(nullptr) {}
}Link;

typedef struct Queue{
    Link* front;
    Link* rear;
    int size;

    Queue(){
        front = rear = new Link(0);
        size = 0;
    }

    void enqueue(int it){
        rear->next = new Link(it);
        rear = rear->next;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            return -1;
        }

        Link* temp = front->next;
        int it = temp->element;
        front->next = temp->next;
        if (rear == temp) {
            rear = front;
        }
        delete temp;
        size--;
        return it;
    }

    void clean(){
        Link* temp = front->next;
        while(temp != nullptr){
            Link* next = temp->next;
            delete temp;
            temp = next;
        }
        front->next = nullptr;
        rear = front; size = 0;
    }

    int frontValue(){
        return front->next->element;
    }

    int Length(){
        return size;
    }

}Queue;

int main() {
    Queue q;

    cout << "Enfileirando 10, 20, 30..." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Tamanho da fila: " << q.size << endl;  // Esperado: 3
    cout << "Elemento front : " << q.frontValue() << endl;
    cout << "Desenfileirando: " << q.dequeue() << endl;  // Esperado: 10
    cout << "Desenfileirando: " << q.dequeue() << endl;  // Esperado: 20

    cout << "Tamanho da fila: " << q.size << endl;  // Esperado: 1

    q.clean();
    cout << "Tamanho da fila apos limpar: " << q.size << endl;  // Esperado: 0

    cout << "Desenfileirando apos limpar: " << q.dequeue() << endl;  // Esperado: -1

    return 0;
}