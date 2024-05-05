#include <iostream> 
using namespace std;

int main(){
    int matriz[3][4];
    int i,j;

    //usa condições aninnhadas para preencher a matriz
    for(i=0;i<3; i++){     //percorre as linhas
        for(j=0;j<3;j++){ //percorre as colunas
            matriz[i][j]=i;
        }
    }

    //imprime os valores
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout << matriz[i][j] << " "; // na mesma linha
        }
        cout << "\n"; //quebra de linha quando acaba a que está processando
    }

    return 0;
}