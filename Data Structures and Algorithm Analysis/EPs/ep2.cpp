#include <bits/stdc++.h>
using namespace std;

typedef struct Link{
    int element;
    Link* next;

    Link(int e): element(e), next(nullptr) {}
}Link;

typedef struct Queue{
    Link* front;
    Link* rear;
    int size; 

    Queue(){
        front = new Link(0);
        rear = front;
        size = 0;
    }

    void enqueue(int it){
        rear->next = new Link(it);
        rear = rear->next;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            return;
        }
        Link* temp = front->next;
        front->next = temp->next;
        if (rear == temp) {
            rear = front;
        }
        delete temp;
        size--;
    }

    void clean(){
        Link* temp = front->next;
        while(temp != nullptr){
            Link* next = temp->next;
            delete(temp);
            temp = next;
        }
        front->next = nullptr;
        front = rear;
        size = 0;
    }

    int frontValue(){
        return front->next->element;
    }

    void print(){
        Link* temp = front->next;
        while (temp != nullptr){
            if(temp != rear){
                cout << temp->element << " ";
                temp = temp->next;
            }
            else{
                cout << temp->element;
                temp = temp->next;
            }
        }
        cout << endl;
    }

    int length(){
        return size;
    }
}Queue;

int main(){
    Queue banco;
    string x; cin >>x;
    int q_resolv = 0;
        
    while(x != "end"){
        if(x == "add"){
            int it; cin >> it;
            banco.enqueue(it);
        }else if(x == "solve"){
            if(banco.size != 0){
                banco.dequeue();
                q_resolv++;
            }
        }else if(x == "print"){
            int t = banco.length();
            if(t != 0){
                banco.print();
            }else{
                cout << "x" << endl;
            }
        }else if(x == "stats"){
            cout << q_resolv << " " << banco.length() << endl;
        }
        cin >> x;
    }   
    cout << endl;
}

