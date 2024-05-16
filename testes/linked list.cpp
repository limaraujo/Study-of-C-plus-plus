#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Link {
    int element;
    Link* next;

    Link(int e) : element(e), next(nullptr) {}
} Link;

typedef struct List {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;

    List() : head(nullptr), tail(nullptr), curr(nullptr), cnt(0) {}
} List;

void clean(List& l) {
    Link* temp = l.head->next;
    while (temp != nullptr) {
        Link* next = temp->next;
        delete temp;
        temp = next;
    }
    l.head->next = nullptr;
    l.curr = l.tail = l.head;
    l.cnt = 0;
}

void insert(List& l, int it) {
    Link* temp = l.curr->next;
    l.curr->next = new Link(it);

    if (l.tail == l.curr) {
        l.tail = l.curr->next;
    }

    l.curr = l.curr->next;
    l.curr->next = temp;
    l.cnt++;
}

void append(List& l, int it) {
    l.tail->next = new Link(it);
    l.tail = l.tail->next;
    l.cnt++;
}

void print(List& l) {
    Link* temp = l.head->next;
    while (temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void moveToStart(List& l) {
    l.curr = l.head; // Movemos para o primeiro elemento
}

void moveToEnd(List& l) {
    l.curr = l.tail; // Movemos para o último elemento
}

void prev(List& l) {
    if (l.curr == l.head) {
        return;
    }
    Link* temp = l.head;
    while (temp->next->next != l.curr) {
        temp = temp->next;
    }
    l.curr = temp;
}

void next(List& l) {
    l.curr = l.curr->next;
}

int length(List& l) {
    return l.cnt;
}

int currPos(List& l) {
    Link* temp = l.head->next; // Começamos do primeiro elemento
    int i = 0;
    while (temp != nullptr && temp != l.curr) {
        temp = temp->next; // Avançamos para o próximo elemento
        i++; // Incrementamos o índice
    }
    return i;
}

void moveToPos(List& l, int it) {
    l.curr = l.head->next; // Começamos do primeiro elemento
    for (int i = 0; i < it; i++) {
        if (l.curr == nullptr) // Se atingirmos o final da lista antes de alcançar a posição desejada
            return;
        l.curr = l.curr->next; // Avançamos para o próximo elemento
    }
}

int getValue(List& l) {
    return l.curr->element;
}

void remove(List& l) {
    if (l.curr->next == nullptr) {
        return;
    }
    if (l.tail == l.curr->next) {
        l.tail = l.curr;
    }
    l.curr->next = l.curr->next->next;
    l.cnt--;
}

int main() {
    List lista;
    lista.curr = lista.tail = lista.head = new Link(0);
    // Teste de inserção de elementos
    append(lista, 10);
    append(lista, 20);
    append(lista, 30);
    append(lista, 40);

    // Deve imprimir: 10 20 30 40
    cout << "Lista inicial: ";
    print(lista);
    cout << endl;

    // Teste de movimentação na lista
    moveToStart(lista); // Mover para a primeira posição (primeiro elemento)
    next(lista); // Avançar para a segunda posição (segundo elemento)

    // Deve imprimir: 20
    cout << "Elemento atual: " << getValue(lista) << endl;

    moveToPos(lista, 2); // Mover para a segunda posição (terceiro elemento)

    // Deve imprimir: 20
    cout << "Elemento atual: " << getValue(lista) << endl;

    moveToEnd(lista); // Mover para a última posição (último elemento)

    // Deve imprimir: 40
    cout << "Elemento atual: " << getValue(lista) << endl;

    // Teste de inserção e remoção de elementos em diferentes posições
    moveToStart(lista);
    insert(lista, 5); // Inserir o elemento 5 na primeira posição

    // Deve imprimir: 5 10 20 30 40
    cout << "Lista após inserção: ";
    print(lista);
    cout << endl;

    moveToPos(lista, 3);
    insert(lista, 15); // Inserir o elemento 15 na terceira posição

    // Deve imprimir: 5 10 15 20 30 40
    cout << "Lista após inserção: ";
    print(lista);
    cout << endl;

    moveToPos(lista, 3);
    remove(lista); // Remover o terceiro elemento (valor 15)

    // Deve imprimir: 5 10 20 30 40
    cout << "Lista após remoção: ";
    print(lista);
    cout << endl;

    // Teste de limpeza da lista
    clean(lista);

    // Deve imprimir apenas uma nova linha
    cout << "Lista limpa." << endl;

    // Verificar se a lista está vazia
    if (lista.head->next == nullptr) {
        cout << "A lista está vazia." << endl;
    } else {
        cout << "A lista não está vazia." << endl;
    }

    return 0;
}

