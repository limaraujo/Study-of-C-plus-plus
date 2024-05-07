#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(b<a){
        swap(a,b);
    }
    if(c<b){
        swap(b,c);
        if(b<a){
            swap(a,b);
        }
    }

    cout << a << endl << b << endl << c;
    cout << endl;
    cout << c << endl << b << endl << a;
    cout << endl;
    return 0;
}