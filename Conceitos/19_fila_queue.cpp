#include <iostream>
#include <queue> 
using namespace std;

int main(){
//Primeiro a entrar é o último a sair

//empty: verifica se está vazia
//size: número de elementos
//front: na frente da fila, não remove
//back: ultimo elemento
//push: adiciona um elemento
//pop: remove a frente da fila

    queue <string> cartas;

    cartas.push("Rei de Copas");
    cartas.push("Rei de Espadas");
    cartas.push("Rei de Ouros");
    cartas.push("Rei de Paus");

    cout << "Tamanho da fila: " << cartas.size() << endl;
    cout << "Primeira carta: " << cartas.front() << endl;
    cout << "Ultima carta: " << cartas.back() << endl;

    //remove pela primeira carta
    while(!cartas.empty()){
        cout << "Primeira carta: " << cartas.front() << endl;
        cartas.pop();
    }


    return 0;
}