//struct
#include <bits/stdc++.h>
using namespace std;

struct Estudante {
    int chegada;
    int espera;
};

typedef struct Link{
    Estudante element;
    Link* next;

    Link(Estudante it): element(it), next(nullptr) {}
}Link;

typedef struct Queue{
    Link* front;
    Link* rear;
    int size; 

    Queue(){
        front = rear = new Link({-1, -1});
        size = 0;
    }

    void enqueue(Estudante it){
        rear->next = new Link(it);
        rear = rear->next;
        size++;
    }

    Estudante dequeue() {
        if (size == 0){ return {-1, -1}; }

        Link* temp = front->next;
        Estudante e = temp->element;
        front->next = temp->next;

        if (rear == temp) {rear = front;}
        delete temp; size--;
        return e;
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

}Queue;

int main(){
    int t; cin >> t;
    Queue estudantes;


    for(int i = 0; i < t; i++){
        int n; cin >> n;
        
        for (int j = 0; j < n; j++) {
            Estudante e;
            cin >> e.chegada >> e.espera;
            estudantes.enqueue(e);
        }

        int time = 1;
        for(int j = 0; j < n; j++) {
            Estudante e = estudantes.dequeue();

            if ( time <= e.chegada){
                cout << e.chegada << " ";
                time = e.chegada + 1;
            }else if(e.chegada <= time && time <= e.espera){
                cout << time << " ";
                time++;
            }else{
                cout << "0 ";
            }       
        }
        cout << endl;
        estudantes.clean();
    }
    return 0;
}
