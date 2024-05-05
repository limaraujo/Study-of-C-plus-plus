#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> aula;
    int tam; tam = 10;

    //inicia a inserção
    list<int>::iterator it;

    for(int i = 0; i<tam; i++){
        aula.push_front(i);
    }

    //para inserir um elemento no meio da lista
    it=aula.begin();
    advance(it,3); //adiciona ao lugar
    aula.insert(it,0);

    aula.erase(--it);//remove um elemento

    for(it = aula.begin(); it !=aula.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    aula.clear(); //limpa a lista

    if(aula.empty()){
        cout<<aula.size();
    }

    return 0;
}