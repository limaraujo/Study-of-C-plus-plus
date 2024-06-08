#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int x;
    vector<int> tam;
    int maior = 0;

    // Leitura dos inteiros até encontrar 0
    while (cin >> x && x != 0) {
        tam.push_back(x);
        if (x > maior) {
            maior = x;
        }
    }

    // Criar  uma tabela com todos os valores a partir do maior tamanho que ela vai assumir
    vector<vector<int>> matriz(maior, vector<int>(maior));
    for (int i = 0; i < maior; i++) {
        for (int j = 0; j < maior; j++) {
            matriz[i][j] = pow(2, i + j);
        }
    }

    // Imprimir as sub matrizes 
    for (int val : tam) {
        int digitCount = to_string(matriz[val-1][val-1]).length();
        for (int i = 0; i < val; i++) {
            for (int j = 0; j < val; j++) {
                cout << setw(digitCount) << matriz[i][j];
                if (j != val - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
