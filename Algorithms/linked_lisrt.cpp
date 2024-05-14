#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Link{
    int element;
    Link* next;

    Link(int e): element(e), next(nullptr) {}
} Link;

typedef struct List{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;

    List(): head(nullptr), tail(nullptr), curr(nullptr), cnt(0) {}
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

void insert(List& l, int it){
    Link* temp = l.curr->next;
    l.curr->next = new Link(it);

    if(l.tail == l.curr){
        l.tail = l.curr->next;
    }

    l.curr = l.curr->next;
    l.curr->next = temp;
    l.cnt++; 
}

void append(List& l, int it){
    l.tail->next = new Link(it);
    l.tail = l.tail->next;
    l.cnt++;
}

void print(List& l){
    Link* temp = l.head->next;
    while (temp != nullptr) {
        cout << temp->element << " ";
        temp = temp->next;
    }
}

void moveToStart(List& l){
    l.curr = l.head->next;
}

void moveToEnd(List& l){
    l.curr = l.tail;
}

void prev(List& l){
    if(l.curr == l.head){
        return;
    }
    Link* temp = l.head;
    while (temp->next->next != l.curr) {
        temp = temp->next;
    }
    l.curr = temp;
}

void next(List& l){
    l.curr = l.curr->next;
}

int length(List& l){
    return l.cnt;
}

int currPos(List& l){
    Link* temp = l.head;
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
    Link* temp = l.head;
    for(int i = 0; i <it; i++){
        temp = temp->next;
    }        
    l.curr = temp;
}

int getValue(List& l){
    return l.curr->element;
}


void remove(List& l){
    if(l.curr->next == nullptr){
        return;
    }
    if(l.tail == l.curr->next){
        l.tail = l.curr;
    }
    l.curr->next = l.curr->next->next;
    l.cnt--;  
}

    
int main(){
    List x;
    x.curr = x.tail = x.head = new Link(0);
    append(x,1);
    append(x,2);
    append(x,3);

    print(x); cout << endl;
    
    next(x);
    next(x);
    cout << getValue(x) << endl;      
    cout << "currPos :" << currPos(x) << endl;    
    
    insert(x,4);
    print(x);
    cout << endl;
    
    append(x,5);
    print(x);
    cout << endl;
    

    prev(x);
    cout << getValue(x) << endl;      
    cout << "currPos :" << currPos(x) << endl;    

    insert(x,7);
    print(x);
    cout << endl;

    moveToStart(x);
    cout << getValue(x) << endl;      
    cout<< "currPos :" << currPos(x) << endl; 

    insert(x,14);
    print(x);
    cout << endl;
    
    
    cout << "len :" << length(x) << endl;
    cout << getValue(x) << endl;      
    cout << "currPos :"  << currPos(x) << endl;

    moveToPos(x, 5);
    cout << "currPos :"  << currPos(x) << endl;
    cout << getValue(x) << endl;

    insert(x,81);
    print(x);
    cout << endl;

    remove(x);
    print(x);
    cout << endl;

    clean(x);
    print(x);
    cout << endl << "Fim!";
}