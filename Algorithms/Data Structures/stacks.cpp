//stack
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
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push(int it){
        Link* temp = new Link(it);
        temp->next = top;
        top = temp;
        size++;
    }

    int length(){
        return size;
    }

    void clean(){
        Link* temp =  top;
        while (temp != nullptr) {
            Link* next = temp->next;
            delete temp;
            temp = next;
        }
        top = nullptr;
        size = 0;
    }

    int pop(){
        if(top == nullptr){
            return -1;
        }
        int it = top->element;
        top = top->next;
        size--;
        return it;
    }
    
    int topValue(){
        return top->element;
    }

} Stack;



int main() {
    Stack stack;    
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    cout << "Length: " << stack.length() << endl;
    cout << "Stack: ";
    stack.printStack();

    cout << stack.pop() << endl;
    
    stack.clean();
    stack.printStack();

    cout << "Fim";
    return 0;
}
