#include <bits/stdc++.h>
using namespace std;

struct Estudantes{
    int chegada;
    int espera;
};


int main(){
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        int n; cin >> n;

        Estudantes* fila = new Estudantes[n];

        for(int i = 0; i < n; i++){
            Estudantes e;
            cin >> e.chegada >> e.espera;
            fila[i] = e;
        }

        int time = 1;
        for (int j = 0; j < n; j++) {
            if (time <= fila[j].chegada){
                cout << time << " ";
                time = fila[j].chegada + 1;
            }else if (time time <= fila[j].espera) {
                cout << time << " ";
                time++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;

        delete[] fila;
    }
    return 0;
}