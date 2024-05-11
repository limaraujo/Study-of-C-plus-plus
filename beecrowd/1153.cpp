#include <iostream>
using namespace std;

int fatorial(int n);

int main() {
    int n; cin >> n;
    
    long long f = fatorial(n);
    
    cout << f;
    
    return 0;
}

int fatorial(int n){
    if(n==1 || n==0){
        return 1;
    }else{
        return fatorial(n-1)*n;
    }
}