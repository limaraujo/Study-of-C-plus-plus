#include <iostream>
#include <string>

using namespace std;

//especificador/nome
struct personagem{  //dados do personagem
    string nome;    //nome do personagem
    string casa;    //casa que faz parte
    int idade;      //idade
    string gosto;     //se gosto ou não

};

/*
serve como um modelo para a criação de variáveis de um dado tipo. O especificador não define 
qualquer variável, ou seja, ele não designa qualquer espaço de memória e nomeia uma variável. 
Ele serve apenas para especifi car como devem ser as variáveis quando definidas.
*/

int main(){

    personagem pers1;
    personagem pers2;

    pers1.nome = "Severus Snape";
    pers1.casa = "Slytherin";
    pers1.idade = 38;
    pers1.gosto = "Favorito";

    pers2.nome = "Remo Lupim";
    pers2.casa = "Gryffindor";
    pers2.idade = 38;
    pers2.gosto = "Curto";
    
    cout << "Nome  " << pers1.nome << endl;
    cout << "Casa  " << pers1.casa << endl;
    cout << "Idade " << pers1.idade << endl;
    cout << "Gosto " << pers1.gosto << endl;
    cout << endl;
    cout << "Nome  " << pers2.nome << endl;
    cout << "Casa  " << pers2.casa << endl;
    cout << "Idade " << pers2.idade << endl;
    cout << "Gosto " << pers2.gosto << endl;

    return 0;
} 