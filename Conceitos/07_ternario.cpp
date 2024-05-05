#include <iostream>

using namespace std;

int main(){

    int n1,n2, nota;

    string res;

    cout << "Digite a primeira nota: \n";
    cin >> n1;
    cout << "Digite a segunda nota: \n";
    cin >> n2;

    nota=n1+n2;

    // >=60 == aprovado
    // <60 == reprovado

    (nota >= 60) ? res = "Aprovado": res="Reprovado";

    cout << "\nSituaçao do aluno: " << res << "\n";

    return 0;
}