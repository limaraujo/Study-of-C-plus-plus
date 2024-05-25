#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort

using namespace std;

int main() {
    // 1. Construtores

    // Default constructor
    vector<int> v1;

    // Fill constructor
    vector<int> v2(5, 10); // 5 elementos, todos com valor 10

    // Range constructor
    vector<int> v3(v2.begin(), v2.end());

    // Copy constructor
    vector<int> v4(v3);

    // Move constructor
    vector<int> v5(std::move(v4));

    // Exibir os elementos de v2
    cout << "Elementos de v2: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Exibir os elementos de v5 (deve ser igual a v3)
    cout << "Elementos de v5 (movidos de v4): ";
    for (const auto& elem : v5) {
        cout << elem << " ";
    }
    cout << endl;

    // 2. Destrutor é chamado automaticamente no final do escopo

    // 3. Atribuição

    // Copy assignment
    vector<int> v6 = v2;

    // Move assignment
    vector<int> v7 = std::move(v3);

    // 4. Element Access

    cout << "Elemento na posição 2 em v2 usando at: " << v2.at(2) << endl;
    cout << "Elemento na posição 2 em v2 usando operator[]: " << v2[2] << endl;
    cout << "Primeiro elemento em v2 usando front: " << v2.front() << endl;
    cout << "Último elemento em v2 usando back: " << v2.back() << endl;

    // Modificando um elemento usando operator[]
    v2[2] = 20;
    cout << "Elemento na posição 2 em v2 após modificação: " << v2[2] << endl;

    // 5. Iterators

    cout << "Elementos de v2 usando iteradores: ";
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterators
    cout << "Elementos de v2 em ordem reversa: ";
    for (auto rit = v2.rbegin(); rit != v2.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // 6. Capacity

    cout << "v2 está vazio? " << (v2.empty() ? "Sim" : "Não") << endl;
    cout << "Tamanho de v2: " << v2.size() << endl;
    cout << "Capacidade de v2: " << v2.capacity() << endl;

    // Reservando capacidade
    v2.reserve(10);
    cout << "Capacidade de v2 após reserve(10): " << v2.capacity() << endl;

    // Reduzindo a capacidade para corresponder ao tamanho
    v2.shrink_to_fit();
    cout << "Capacidade de v2 após shrink_to_fit(): " << v2.capacity() << endl;

    // 7. Modifiers

    // Limpando todos os elementos
    v2.clear();
    cout << "Tamanho de v2 após clear(): " << v2.size() << endl;

    // Inserindo elementos
    v2.insert(v2.begin(), 5);
    v2.insert(v2.end(), {6, 7, 8});
    cout << "Elementos de v2 após insert: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Emplace - construir e inserir um elemento na posição
    v2.emplace(v2.begin() + 1, 10);
    cout << "Elementos de v2 após emplace: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Apagando elementos
    v2.erase(v2.begin() + 2);
    cout << "Elementos de v2 após erase: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Adicionando elementos no final
    v2.push_back(9);
    cout << "Elementos de v2 após push_back: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Emplace_back - construir e adicionar um elemento no final
    v2.emplace_back(11);
    cout << "Elementos de v2 após emplace_back: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Remover o último elemento
    v2.pop_back();
    cout << "Elementos de v2 após pop_back: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Redimensionando o vector
    v2.resize(5, 100);
    cout << "Elementos de v2 após resize(5, 100): ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;

    // Trocando conteúdo de dois vectors
    vector<int> v8 = {1, 2, 3};
    v2.swap(v8);
    cout << "Elementos de v2 após swap com v8: ";
    for (const auto& elem : v2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Elementos de v8 após swap com v2: ";
    for (const auto& elem : v8) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
