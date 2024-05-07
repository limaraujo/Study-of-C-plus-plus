#include <iostream>
#include <string>
using namespace std;

int main(){
    int linhas; cin >> linhas;
    cin.ignore();

    for (int k = 0; k < linhas; k++){   
        string linha; getline(cin,linha);
        int linha_ascii[10000] = {};
        int i = 0;

        for(char&c : linha){
            int l = static_cast<int>(c);
            if((l >= 65 && l <=90) || (l >= 97 && l <= 122)){ 
                l += 3;
            }
            linha_ascii[i] = l;
            i++;
        }

        int fim = i-1; int inicio = 0;
        while (inicio < fim) {
            swap(linha_ascii[inicio++], linha_ascii[fim--]);
        }

        for(int j = i/2; j < i; j++){
            linha_ascii[j] = linha_ascii[j]-1;
        }

        for(int j = 0; j < i; j++){
            cout << static_cast<char>(linha_ascii[j]);
        }

        cout << endl;
    }

    return 0;
}