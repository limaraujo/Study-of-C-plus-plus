#include <iostream>

using namespace std;

/*
 armazena elementos do mesmo tipo em uma sequência contígua de memória; 
 int num[5] = {1,2,3,4,5} é caracterizado pelo tipo e quantidade de posições
 possuí indices; começa pelo 0
*/

int main() {
    int vetor[5];
    int i;

    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;
    vetor[3] = 40;
    vetor[4] = 50;

    cout << vetor[1] << "\n"; // saida de uma dada posição

    // para printar todas as posições
    for (i = 0; i < 5; i++) {
        cout << vetor[i] << "\n";
    }

    // sizeoof retorna o tamanho do tipo
    // para inteiros o tamanho é 4

    cout << "Metodo: sizeof\n";
    for (i = 0; i < sizeof(vetor) / 4; i++) {
        cout << vetor[i] << "\n";
    }

    int tam = 5; // com o tamanho da array como constante
    int vetor1[tam] = {10, 20, 30, 40, 50}; // para atribuir diretamente

    for (i = 0; i < tam; i++)
        cout << vetor1[i] << "\n";

    return 0;
}
