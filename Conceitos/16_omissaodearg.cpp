#include <iostream>
using namespace std;

void imp(string txt="Abel Ferreira");// é passado um valor pardrão
// permite a chamada com omissão de argumento


int main(){

    imp();
    imp("melhor tecnico do mundo");

    return 0;
}

void imp(string txt){
    cout << endl << txt << endl;
}