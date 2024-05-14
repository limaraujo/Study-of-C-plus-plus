#include <iostream>

using namespace std;

struct Link {
    int element;
    Link* next;
    
    Link(int e) : element(e), next(nullptr) {}
};

struct List {
    Link* head;
    Link* tail;
    Link* curr;
    int cnt;
    
    List() : head(nullptr), tail(nullptr), curr(nullptr), cnt(0) {}
};

void insert(List& l, int it) {
    Link* newLink = new Link(it);
    if (!l.head) {
        l.head = newLink;
        l.tail = l.head;
        l.curr = l.head;
    } else {
        newLink->next = l.curr->next;
        l.curr->next = newLink;
        if (l.curr == l.tail) {
            l.tail = newLink;
        }
    }
    l.cnt++;
}

void print(const List& l) {
    Link* current = l.head;
    while (current) {
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    List x;
    insert(x, 2);
    insert(x, 3);
    print(x);
    return 0;
}