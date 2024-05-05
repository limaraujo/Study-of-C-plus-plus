#include <iostream>
using namespace std;

int n1, n2; //variáveis globais

int main(){

    //Operadores Matemáticos: + - / % ()
    // Igual a python

    int n3, n4; //variáveis locais
    int res;

    n1=11;
    n2=3;
    n3=5;
    n4=2;

    res=n1+n2+n3+n4-10;

    cout << "Soma de todas as variaveis: " << res << "\n";


    return 0;
}