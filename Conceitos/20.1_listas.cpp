#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> aula;

    //inicia o interador
    list<int>::iterator it;

    aula.push_front(7);
    aula.push_front(4);
    aula.push_front(6);
    aula.push_front(8);
    aula.push_front(9);
    aula.push_front(0);
    aula.push_front(2);
    aula.push_front(1);
    aula.push_front(3);
    aula.push_front(5);

    aula.sort(); //ordena

    for(it = aula.begin(); it !=aula.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    aula.reverse(); //ordena ao contrario 
    for(it = aula.begin(); it !=aula.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}