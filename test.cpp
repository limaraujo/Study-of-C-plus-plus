#include <bits/stdc++.h>
using namespace std;

/*int Hash(string k){
    int i = 1; int chave = 0;
    for(char c: k){
        chave += c* i ++;
        cout << int(c) << " ";
    }
    cout << chave << "\n";

    return (19*chave) %101;
}

int main(){
    int cases; cin >> cases;
    for(int i = 0; i < cases; i++){
        string s; cin >> s;
        cout << Hash(s)<< "\n";}
    return 0;
}*/


int main() {
    string operation;
    string key;

    // Recebendo a entrada e dividindo diretamente
    getline(cin, operation, ':');
    getline(cin, key);

    // Imprimindo as strings
    cout << "Operation: " << operation << endl;
    cout << "Key: " << key << endl;

    return 0;
}
