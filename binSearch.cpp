#include <bits/stdc++.h>
using namespace std;

bool binSearch(int A[], int l, int r, int k) {
    int m = (l - 2) / 2; // Cálculo correto do meio
    if (m <0){return false;}

    if (A[m] == k) { // Verificar se o elemento do meio é o elemento procurado
        return true;
    } else if (A[m] > k) { // Buscar na metade esquerda
        return binSearch(A, l, m - 1, k);
    } else { // Buscar na metade direita
        return binSearch(A, m + 1, r, k);
    }
}

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    int n; 
    cin >> n;
    cout << (binSearch(A, 1, 5, n) ? "S" : "N") << endl; // Corrigir os índices e a expressão ternária
}
