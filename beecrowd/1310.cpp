#include <iostream>
using namespace std;

int main(){
    int num_dias;

    while (cin >> num_dias){
        int custo_dia; cin >> custo_dia; 
        int receita_dia; int receitas[num_dias] ={};

        for(int i = 0; i < num_dias; i++){
            cin >> receita_dia;
            receitas[i] = receita_dia - custo_dia;
        }

        int lucro_maximo = 0; int lucro = 0;
        for(int i = 0; i < num_dias; i++){
            lucro += receitas[i];
            if(lucro_maximo < lucro){
                lucro_maximo = lucro;
            }
            if(lucro < 0){
                lucro = 0;
            }
        }

        cout << lucro_maximo << endl;

    }   
    
    return 0;
}