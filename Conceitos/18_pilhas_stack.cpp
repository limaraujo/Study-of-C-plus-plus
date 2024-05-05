#include <iostream>
#include <stack> 

using namespace std;

int main(){
    //pega sempre os elementos do top
    //primeiro a entrar, último a sair

    //pilha <tipo> nome;
    stack <string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    //tamanho da pilha, mesma coisa de lem do python
    cout << "Tamanho da pilha " << cartas.size() << endl;

    //para visualizar o elemento do topo
    cout << "Cartas do topo " << cartas.top() << endl;

    //retira o ultimo elemento/top
    cartas.pop();

    cout << "Tamanho da pilha " << cartas.size() << endl;

     // Verifica se a pilha está vazia (True or False)
    if (cartas.empty()) {
        cout << "A pilha esta vazia." << endl;
    } else {
        cout << "A pilha nao esta vazia." << endl;
    }

    cartas.push("Rei de Paus");

    //a pilha é acessada pelo elemento do topo
    while(!cartas.empty()){
        cout << "Carta do topo: " << cartas.top() << endl;
        cartas.pop();
    }

    return 0;
}
