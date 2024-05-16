#include <iostream>
#include <cmath>

using namespace std;

void binary(int arr[], int n) {
    for(int i = 0; i < 32; i++) {
        arr[i] = n % 2;
        n = n / 2;
    }
}

int decimal(int arr[]) {
    int result = 0;

    for(int i = 0; i < 32; i++) {
        if (arr[i] != 0) {
            result += pow(2, i);
        }
    }
    return result;
}

void sum(int arr_a[], int arr_b[], int arr_c[]) {
    
    for(int i = 0; i < 32; i++) {
        arr_c[i] = arr_a[i] ^ arr_b[i]; 
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {    
        int arr_a[32], arr_b[32], arr_c[32] = {};

        binary(arr_a, a);
        binary(arr_b, b);
        sum(arr_a, arr_b, arr_c);

        cout << decimal(arr_c) << endl;
    }

    return 0;
}