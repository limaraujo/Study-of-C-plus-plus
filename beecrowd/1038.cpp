#include <iostream>
#include <iomanip> 
using namespace std;

int main(){
    float arr[5] = {4.00, 4.50, 5.00, 2.00, 1.50};
    float v, t;
    int x;

    cin >> x; cin >> t;
    v = arr[x-1]*t;

    
    cout << fixed << setprecision(2);
    cout  << "Total: R$ " << v <<endl;

    return 0;
}