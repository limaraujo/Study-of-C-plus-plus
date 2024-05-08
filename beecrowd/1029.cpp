#include <iostream>
using namespace std;

int fibonacci(int n, int &c);

int main(){
    int i; cin >> i;

    for(int j = 0; j < i; j++){
        int n; cin >> n;
        int c = 0;
        int resultado = fibonacci(n ,c);
        cout << "Fib(" << n << ") = " << c-1 << " calls = " << resultado << endl;
    }
}


int fibonacci(int n, int &c){
    c++;
    if(n == 1 || n == 0){
        return n;
    }else{
        return fibonacci(n-1, c) + fibonacci(n-2, c);
    }
}