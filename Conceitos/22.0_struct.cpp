#include <iostream>
#include <string>

using namespace std;

//especificador/nome
struct personagem{  //dados do personagem
    string nome;    //nome do personagem
    string casa;    //casa que faz parte
    int idade;      //idade
    string gosto;     //se gosto ou não

    void insert(string stnome, string stcasa, int stidade, string stgosto){
        nome = stnome;
        casa = stcasa;
        idade = stidade;
        gosto = stgosto;
    };

    void print(){
        cout << "Nome:.... " << nome << endl;
        cout << "Casa:.... " << casa << endl;
        cout << "Idade:... " << idade << endl;
        cout << "Gosto:... " << gosto << endl;
        cout << endl;

    };

    void mudar_estatus(string stgosto){
        gosto = stgosto;
    };


};

/*
serve como um modelo para a criação de variáveis de um dado tipo. O especificador não define 
qualquer variável, ou seja, ele não designa qualquer espaço de memória e nomeia uma variável. 
Ele serve apenas para especifi car como devem ser as variáveis quando definidas.
*/

int main(){

    personagem pers1;
    personagem pers2;

    pers1.insert("Severus Snape","Slytherin",38,"Favorito");
    pers2.insert( "Remo Lupim", "Gryffindor", 38,"Curto");

    pers1.print();
    pers2.print();

    pers1.mudar_estatus("After all this time");
    pers1.print();

    return 0;
} 