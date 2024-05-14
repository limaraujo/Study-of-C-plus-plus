#include <iostream>

using namespace std;

int main(){
    int *p;
    int vetor[10];

    p=&vetor[0]; //p=vetor;
    cout << "\n" << p << "\n";
    
    p=&vetor[1];
    cout << "\n" << p << "\n";

    p=&vetor[2];
    cout << "\n" << p << "\n";

    //ou:
    p=vetor;
    cout << "\n" << p << "\n";

    //*(++p);
    cout << "\n" << p << "\n";

    //*(++p);
    cout << "\n" << p << "\n";

}