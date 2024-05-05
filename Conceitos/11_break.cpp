#include <iostream>

using namespace std;

int main(){

    int cont;
    cont=0;

    while(cont <= 1000){
        cout << cont <<  "\n";
        if(cont == 100){
            break;
        }
        cont ++;
    }
}