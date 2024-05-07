#include <iostream>
using namespace std;

void margesort(int arr[], int inicio, int fim);
void marge(int arr[], int inicio, int meio, int fim);

int main(){
    int fim; cin >> fim;
    int arr[fim];

    for(int i = 0; i < fim; i++){
        cin >> arr[i];  
    }

    margesort(arr, 0, fim-1);

    for(int i = 0; i < fim; i++){
        cout << arr[i] << " ";  
    }

    cout << endl;

    for(int i = fim-1; i >= 0; i--){
        cout << arr[i] << " ";  
    }

    return 0;
}

void margesort(int arr[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        margesort(arr, inicio ,meio);
        margesort(arr, meio + 1, fim);
        marge(arr, inicio, meio, fim);
    }
}

void marge(int arr[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int temp[n1];

    for(int i = 0; i < n1; i++){
        temp[i] = arr[inicio + i];
    }

    i = 0; j = meio + 1; k = inicio;

    while(i < n1 && j <= fim){
        if(temp[i] <= arr[j]){
            arr[k++] = temp[i++];
        }else{
            arr[k++] = arr[j++];
        }
    }

    while(i < n1){
        arr[k++] = temp[i++];
    }
}
