#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float a, b, c;
    cout << fixed << setprecision(1);

    cin >> a >> b >> c;

    if(a+b > c && a+c > b && b+c > a){
        float perimetro = a + b + c;
        cout << "Perimetro = " << perimetro << endl;
    }else{
        float area = (a + b)*c / 2;
        cout << "Area = " << area << endl;
    }

    return 0;
}