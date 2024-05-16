#include <iostream>

using namespace std;

typedef struct Link {
    int element;
    Link* next;
    
    Link(int e) : element(e), next(nullptr) {}
} Link;

typedef struct Stack {
    Link* top;
    int size;

    Stack() : top(nullptr), size(0) {}

    void printStack(){
        Link* temp = top;
        while (temp != nullptr){
            /* code */
        }
        
    }

    void push(int it){
        Link* temp = new Link(it);
        top->next= top;
        top = temp;
        size++;
    }


} Stack;



int main() {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    cout << stack.length();
    stack.printStack();
    
    return 0;
}
