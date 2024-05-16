#include <iostream>
#include <cstring> 
using namespace std;

struct dados{
    int DDD;
    string destination;
};

int main(){
    dados arr[8];
    
    arr[0].DDD = 61; arr[0].destination = "Brasilia";
    arr[1].DDD = 71; arr[1].destination = "Salvador";
    arr[2].DDD = 11; arr[2].destination = "Sao Paulo";
    arr[3].DDD = 21; arr[3].destination = "Rio de Janeiro";
    arr[4].DDD = 32; arr[4].destination = "Juiz de fora";
    arr[5].DDD = 19; arr[5].destination = "Campinas";
    arr[6].DDD = 27; arr[6].destination = "Vitoria";
    arr[7].DDD = 31; arr[7].destination = "Belo Horizonte";

    int DDD; cin >> DDD; bool ddd = false;
    for(int i=0; i < 8; i++){
        if(DDD == arr[i].DDD){
            cout << arr[i].destination << endl;
            ddd = true;
        }
    }

    if(!ddd){ cout << DDD << endl;}

    return 0;
}
