#include <iostream>

using namespace std;

int main(){
    int cont;
    cin >> cont;

    do{
        if(cont <10){
            cout << "Number - " << cont << "\n";
            cont++;
        }
        
    }while(cont<10);

    cout << "\nrotina finalizada\n";

    return 0;
}