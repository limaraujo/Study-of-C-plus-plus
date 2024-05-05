#include <iostream>

using namespace std;

int main(){

    //TIPO NOME:
    //TIPO NOME * VALOR;

    int vidas=0; //recebe números inteiros
    char letra='B'; // 'B' um byte
    double decimal=2.499; //2,49999999
    float maiorprecisao = 2.5; // decimal com precissão menor 2.5
    bool vivo=true; //true== 1 or false == 0
    string nome="Bruno"; //texto "Bruno"

    cout << vidas << "\n";
    cout << letra << "\n";
    cout << decimal << "\n";
    cout << maiorprecisao << "\n";
    cout << vivo << "\n";
    cout << nome << "\n";

    /*
    cout << vidas << "\n" << letra << "\n" << decimal << "\n" << maiorprecisao << "\n" << vivo << "\n" << nome << "\n";
    */

    int numero;

    cout << "Digite um numero";
    cin >> numero;

    cout << numero << "\n";
   
    return 0;
}