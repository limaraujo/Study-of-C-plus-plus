#include <iostream>
using namespace std;

void merge(string arr_nomes[], int arr_notas[], int arr_idades[], int inicio, int fim, int n);
void mergesort(string arr_nomes[], int arr_notas[], int arr_idades[], int inicio, int fim, int n);

int main(){
    int cargos; cin >> cargos;

    for(int c = 0; c < cargos; c++){
        int n; cin >> n;
        int vagas; cin >> vagas;
        string arr_nomes[n] = {};
        int arr_notas[n] = {};
        int arr_idades[n] = {};

        for(int i = 0; i < n; i++){
            cin >> arr_nomes[i];
            cin >> arr_notas[i];
            cin >> arr_idades[i];
        }

        mergesort(arr_nomes, arr_notas, arr_idades, 0, n-1, n);

        cout << "cargo " << c+1 << ":" << endl;
        for(int i = 0; i < vagas; i++){
            if(i < n){
                cout << arr_nomes[i] << endl;
            }else{
                cout << "x" << endl;
            }
            
        }
    }
}

void mergesort(string arr_nomes[], int arr_notas[], int arr_idades[], int inicio, int fim, int n){
    if(inicio < fim){
        int m = (inicio + fim) / 2;
        mergesort(arr_nomes, arr_notas, arr_idades, inicio, m, n);
        mergesort(arr_nomes, arr_notas, arr_idades, m + 1, fim, n);
        merge(arr_nomes, arr_notas, arr_idades, inicio,fim, n);
    }
}

void merge(string arr_nomes[], int arr_notas[], int arr_idades[], int inicio, int fim, int n){
    string temp_nomes[n]={};
    int temp_notas[n]={};
    int temp_idades[n]={};
    
    for(int i = inicio; i <= fim; i++){
        temp_nomes[i] = arr_nomes[i];
        temp_notas[i] = arr_notas[i];
        temp_idades[i] = arr_idades[i];
    }

    int meio = (inicio + fim) / 2;
    int i1 = inicio; 
    int i2 = meio + 1;

    for(int k = inicio; k <= fim; k++){
        if(i1 == meio + 1){
            arr_nomes[k] = temp_nomes[i2];
            arr_notas[k] = temp_notas[i2];
            arr_idades[k] = temp_idades[i2];
            i2++;
        }else if(i2 > fim){
            arr_nomes[k] = temp_nomes[i1];
            arr_notas[k] = temp_notas[i1];
            arr_idades[k] = temp_idades[i1];
            i1++;
        }else if(temp_notas[i1] > temp_notas[i2]){
            arr_nomes[k] = temp_nomes[i1];
            arr_notas[k] = temp_notas[i1];
            arr_idades[k] = temp_idades[i1];
            i1++;
        }else if(temp_notas[i1] == temp_notas[i2]){
            if(temp_idades[i1] >= temp_idades[i2]){
                arr_nomes[k] = temp_nomes[i1];
                arr_notas[k] = temp_notas[i1];
                arr_idades[k] = temp_idades[i1];
                i1++;
            }else{
                arr_nomes[k] = temp_nomes[i2];
                arr_notas[k] = temp_notas[i2];
                arr_idades[k] = temp_idades[i2];
                i2++;
            }
        }else{
            arr_nomes[k] = temp_nomes[i2];
            arr_notas[k] = temp_notas[i2];
            arr_idades[k] = temp_idades[i2];
            i2++;
        }
    } 
}
