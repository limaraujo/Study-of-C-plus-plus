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
    advance(it,5); //adiciona ao lugar
    aula.insert(it,0);

    cout << "Tamanho da lista: " << aula.size() << "\n\n";
    tam = aula.size();
    for(int i = 0; i < tam; i++){
        cout << aula.back() << endl;
        aula.pop_back();
    }
    cout << endl;

    return 0;
}