#include <iostream>
using namespace std;

int main(){
    //armazena o endereço de memória 
    int x = 10;
    double y = 20.5;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    double soma = *pX + *pY;

    printf("Endereco x = %i - Valor x = %i\n", pX, *pX);

    printf("Valor x= %f\n", soma);
    getchar();

    return  0;
}