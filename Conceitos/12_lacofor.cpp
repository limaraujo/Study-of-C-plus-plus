#include <iostream> 

using namespace std;

int main(){
    //for(x=0; x<10; x++){
    // 1º variavel inicial; 2ª condição de parada; 3º incremento;

   int x, y;

   for(x=1, y=1; x<=10; x++, y+=2){
    cout << x << " - " << y <<"\n";
   }

    return 0;
}