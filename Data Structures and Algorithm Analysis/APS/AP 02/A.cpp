#include <iostream>
using namespace std;

typedef struct Link{
    char element;
    Link* next;

    Link(char e) : element(e), next(nullptr) {}
} Link;

typedef struct List{
    Link *header;
    Link *tail;
    Link *curr;
    int cnt;

    List(): header(nullptr), tail(nullptr), curr(nullptr), cnt(0) {}
} List;

void creatList(List& l){
    l.header = l.tail = l.curr = new Link(0);
}

void insert(List& l, char c){
    Link* temp = l.curr->next;
    l.curr->next = new Link(c);
    if(l.curr == l.tail){
        l.tail = l.curr->next;
    }
    l.curr = l.curr->next;
    l.curr->next = temp;

    l.cnt++;
}

void append(List& l, char c){
    l.tail->next = new Link(c);
    l.tail = l.tail->next;
    l.cnt++;
}

void moveToStart(List& l){
    l.curr = l.header;
}

void moveToEnd(List &l){
    l.curr = l.tail;
}

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

void print(List& l){
    Link* temp = l.header->next;

    while (temp != nullptr) {
        cout << temp->element;
        temp = temp->next;
    }
 }

int main() {
    List char_list; 
    creatList(char_list);

    char c;
    while (cin.get(c)) {
        if (c == '\n') {
            print(char_list);
            cout << endl;
            clean(char_list);
        } else if (c == '[') {
            moveToStart(char_list);
        } else if (c == ']') {
            moveToEnd(char_list);
        } else {
            insert(char_list, c);
        }
    }

    return 0;
}