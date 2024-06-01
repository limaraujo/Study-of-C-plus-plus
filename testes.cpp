#include <iostream>
#include <cmath>

// Define a estrutura de um elemento na tabela
struct Elemento {
    int valor;
};

// Declaração da tabela e tamanho
const int SIZE = 8;
Elemento table[SIZE];

// Função de hashing
int hashing(int k, int size) {
    return k - (size * static_cast<int>(std::floor(static_cast<double>(k) / size)));
}

// Função find
int find(int k, int Perm[], int size) {
    int idx = hashing(k, size);
    int startIdx = idx;
    if (table[idx].valor != -1) {
        for (int j = 0; j < size - 1; j++) {
            int p = Perm[j-1];
            idx = (startIdx + p) % size;
            if (table[idx].valor == -1) {
                return idx;
            }
        }
    } else {
        return idx;
    }
    return -1;
}

int main() {
    // Inicializa a tabela com -1 (indicando vazia)
    for (int i = 0; i < SIZE; i++) {
        table[i].valor = -1;
    }

    // Permutação fornecida
    int Perm[SIZE - 1] = {2, 6, 7, 3, 1, 4, 5};

    // Valores para inserir
    int valores[] = {2, 4, 8, 16, 32, -12};
    int numValores = sizeof(valores) / sizeof(valores[0]);

    // Inserção dos valores na tabela
    for (int i = 0; i < numValores; i++) {
        int k = valores[i];
        int index = find(k, Perm, SIZE);
        std::cout << "Valor " << k << ", índice encontrado: " << index << std::endl;

        // Inserindo o valor na tabela
        if (index != -1) {
            table[index].valor = k;
            std::cout << "Valor " << k << " inserido na posição " << index << std::endl;
        } else {
            std::cout << "Nenhuma posição encontrada para o valor " << k << std::endl;
        }
    }

    std::cout << find(5, Per, 8)

    // Imprimindo a tabela resultante
    std::cout << "\nTabela de hash:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << i << ": " << table[i].valor << std::endl;
    }

    return 0;
}
