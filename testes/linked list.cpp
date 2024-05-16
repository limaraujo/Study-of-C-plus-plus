#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Link{
    int element;
    Link* next;

    Link(int e) : element(e), next(nullptr) {}
} Link;

typedef struct List{
    Link *header;
    Link *tail;
    Link *curr;
    int cnt;

    List(): header(nullptr), tail(nullptr), curr(nullptr), cnt(0) {}
} List;

void clean(List& l) {
    Link* temp = l.header->next;
    while (temp != nullptr) {
        Link* next = temp->next;
        delete temp;
        temp = next;
    }
    l.header->next = nullptr;
    l.curr = l.tail = l.header;
    l.cnt = 0;
}

void insert(List& l, int it){
    Link* temp = l.curr->next;
    l.curr->next = new Link(it);

    if(l.tail == l.curr){
        l.tail = l.curr->next;
    }

    l.curr->next->next = temp;
    l.cnt++; 
}

void append(List& l, int it){
    l.tail->next = new Link(it);
    l.tail = l.tail->next;
    l.cnt++;
}

void print(List& l){
    Link* temp = l.header->next;
    while (temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void moveToStart(List& l){
    l.curr = l.header;
}

void moveToEnd(List& l){
    l.curr = l.tail;
}

void prev(List& l) {
    if (l.curr == l.header) {
        return;
    }
    Link* temp = l.header;
    while (temp->next != l.curr) {
        temp = temp->next;
    }
    l.curr = temp; 
}

void next(List& l){
    if(l.curr != l.tail){
        l.curr = l.curr->next;
    }
}

int length(List& l){
    return l.cnt;
}

int currPos(List& l){
    Link* temp = l.header;
    int i = 0;
    do{
        if(temp != l.curr){
            temp = temp->next;
            i++;
        }
    }while(temp != l.curr);
    
    return i;
}

void moveToPos(List& l, int it){
    Link* temp = l.header;
    for(int i = 0; i <it; i++){
        temp = temp->next;
    }        
    l.curr = temp;
}

int getValue(List& l){
    return l.curr->element;
}


void remove(List& l){
    if(l.curr == nullptr){
        return;
    }
    if(l.tail == l.curr->next){
        delete(l.tail);
        l.tail = l.curr;
    }
    l.curr->next = l.curr->next->next;
    l.cnt--;  
}

int main() {
    List myList;
    myList.curr = myList.header = myList.tail = new Link(0);

    // Adicionando elementos à lista utilizando um loop for
    for (int i = 0; i < 5; ++i) {
        insert(myList, i * 10);
    }

    // Imprimindo os elementos da lista
    cout << "Lista após inserção inicial: ";
    print(myList);
    cout << endl;

    // Movendo o cursor para a posição 3 na lista
    moveToPos(myList, 3);

    // Inserindo um novo elemento após a posição atual (posição 3)
    insert(myList, 35);

    // Imprimindo os elementos da lista após a inserção
    cout << "Lista após inserção: ";
    print(myList);
    cout << endl;

    // Movendo o cursor para o final da lista
    moveToEnd(myList);

    // Removendo o último elemento da lista
    remove(myList);

    // Imprimindo os elementos da lista após a remoção
    cout << "Lista após remoção do último elemento: ";
    print(myList);
    cout << endl;

    // Inserindo um novo elemento após a posição atual (último elemento)
    insert(myList, 50);

    // Imprimindo os elementos da lista após a inserção
    cout << "Lista após inserção no final: ";
    print(myList);
    cout << endl;

    // Movendo o cursor para a posição 2 na lista
    moveToPos(myList, 2);

    // Removendo o elemento atual (10)
    remove(myList);

    // Imprimindo os elementos da lista após a remoção
    cout << "Lista após remoção do elemento na posição 2: ";
    print(myList);
    cout << endl;

    // Limpa a lista
    clean(myList);

    // Imprimindo a lista após limpar
    cout << "Lista após limpeza: ";
    print(myList);
    cout << endl;

    return 0;
}


