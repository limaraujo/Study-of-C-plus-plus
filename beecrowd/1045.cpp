#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    float arr[3] = {};
    
    for(int i=0; i<3; i++){
        cin >> arr[i];
    }

    sort(arr, arr+3, greater<float>()); // Ordena em ordem decrescente

    float a = arr[0], b = arr[1], c = arr[2];
    if(a < b + c){
        if(a * a == b * b + c * c){
            cout << "TRIANGULO RETANGULO" << endl;
        }
        if(a * a > b * b + c * c){
            cout << "TRIANGULO OBTUSANGULO" << endl;
        }
        if(a * a < b * b + c * c){
            cout << "TRIANGULO ACUTANGULO" << endl;
        }
        if(a == b || a == c || b == c){
            cout << "TRIANGULO ISOSCELES" << endl;
        }else if(a == b && b == c){
            cout << "TRIANGULO EQUILATERO" << endl;
        }

        
    }else{
        cout << "NAO FORMA TRIANGULO" << endl;
    }
    return 0;
}
