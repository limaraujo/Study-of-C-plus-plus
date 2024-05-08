#include <iostream>
using namespace std;

void margesort(int arr[], int inicio, int fim, int n);
void marge(int arr[], int inicio, int fim, int n);

int main(){
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];  
    }

    margesort(arr, 0, n-1, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";  
    }

    cout << endl;

    for(int i = n-1; i >= 0; i--){
        cout << arr[i] << " ";  
    }

    return 0;
}

void margesort(int arr[], int inicio, int fim, int n){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        margesort(arr, inicio ,meio, n);
        margesort(arr, meio + 1, fim, n);
        marge(arr, inicio, fim, n);
    }
}

void marge(int arr[], int inicio, int fim, int n){
    int temp[n]; 
    for(int i = inicio; i <= fim; i++){
        temp[i] = arr[i];
    }

    int meio = (inicio + fim) / 2;
    int i1 = inicio; int i2 = meio +1;

    for(int k = inicio; k <= fim; k++){
        if(i1 == meio +1){
            arr[k] = temp[i2++];
        }else if(i2 > fim){
            arr[k] = temp[i1++];
        }else if(temp[i1] <= temp[i2]){
            arr[k] = temp[i1++];
        }else{
            arr[k] = temp[i2++];
        }
    }
}

