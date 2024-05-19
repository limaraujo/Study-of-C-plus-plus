#include <bits/stdc++.h>
using namespace std;

struct Link {
    int element;
    Link* next;

    Link(int it): element(it), next(nullptr) {}
};

struct Queue {
    Link* front;
    Link* rear;
    int size; 

    Queue() {
        front = new Link(0); // nó sentinela
        rear = front;
        size = 0;
    }   

    ~Queue() {
        clean();
        delete front; // liberar o nó sentinela
    }

    void enqueue(int it) {
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

    void clean() {
        Link* temp = front->next;
        while (temp != nullptr) {
            Link* next = temp->next;
            delete temp;
            temp = next;
        }
        front->next = nullptr;
        rear = front;
        size = 0;
    }
};

int main() {
    Queue q;

    // Teste de enfileirar
    cout << "Enfileirando 10, 20, 30..." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Teste de tamanho
    cout << "Tamanho da fila: " << q.size << endl;  // Esperado: 3

    // Teste de desenfileirar
    cout << "Desenfileirando: " << q.dequeue() << endl;  // Esperado: 10
    cout << "Desenfileirando: " << q.dequeue() << endl;  // Esperado: 20

    // Tamanho após desenfileirar
    cout << "Tamanho da fila: " << q.size << endl;  // Esperado: 1

    // Teste de limpar a fila
    q.clean();
    cout << "Tamanho da fila após limpar: " << q.size << endl;  // Esperado: 0

    // Teste de desenfileirar após limpar
    cout << "Desenfileirando após limpar: " << q.dequeue() << endl;  // Esperado: -1

    return 0;
}
