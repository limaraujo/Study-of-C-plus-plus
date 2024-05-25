#include <iostream>
#include <set>

using namespace std;

int main() {
    // 1. Construtores

    // Default constructor
    set<int> s1;

    // Range constructor
    int arr[] = {1, 2, 3, 4, 5};
    set<int> s2(arr, arr + 5);

    // Copy constructor
    set<int> s3(s2);

    // Move constructor
    set<int> s4(std::move(s3));

    // Exibir os elementos de s2
    cout << "Elementos de s2: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;

    // Exibir os elementos de s4 (deve ser igual a s2)
    cout << "Elementos de s4 (movidos de s3): ";
    for (const auto& elem : s4) {
        cout << elem << " ";
    }
    cout << endl;

    // 2. Destrutor é chamado automaticamente no final do escopo

    // 3. Atribuição

    // Copy assignment
    set<int> s5 = s2;

    // Move assignment
    set<int> s6 = std::move(s4);

    // 4. Element Access

    cout << "Encontrando o elemento 3 em s2: " << (s2.find(3) != s2.end() ? "Encontrado" : "Não encontrado") << endl;
    cout << "Número de ocorrências do elemento 3 em s2: " << s2.count(3) << endl;

    // 5. Iterators

    cout << "Elementos de s2 usando iteradores: ";
    for (auto it = s2.begin(); it != s2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterators
    cout << "Elementos de s2 em ordem reversa: ";
    for (auto rit = s2.rbegin(); rit != s2.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // 6. Capacity

    cout << "s2 está vazio? " << (s2.empty() ? "Sim" : "Não") << endl;
    cout << "Tamanho de s2: " << s2.size() << endl;

    // 7. Modifiers

    // Limpando todos os elementos
    s1.clear();
    cout << "Tamanho de s1 após clear(): " << s1.size() << endl;

    // Inserindo elementos
    s1.insert(10);
    s1.insert(20);
    s1.insert(10); // Tentativa de inserir um elemento duplicado (não terá efeito)
    cout << "Elementos de s1 após insert: ";
    for (const auto& elem : s1) {
        cout << elem << " ";
    }
    cout << endl;

    // Emplace - construir e inserir um elemento
    s1.emplace(15);
    cout << "Elementos de s1 após emplace: ";
    for (const auto& elem : s1) {
        cout << elem << " ";
    }
    cout << endl;

    // Apagando elementos
    s1.erase(s1.find(10));
    cout << "Elementos de s1 após erase: ";
    for (const auto& elem : s1) {
        cout << elem << " ";
    }
    cout << endl;

    // Trocando conteúdo de dois sets
    s2.swap(s1);
    cout << "Elementos de s2 após swap com s1: ";
    for (const auto& elem : s2) {
        cout << elem << " ";
    }
    cout << endl;
    cout << "Elementos de s1 após swap com s2: ";
    for (const auto& elem : s1) {
        cout << elem << " ";
    }
    cout << endl;

    // 8. Operations

    // lower_bound e upper_bound
    auto lb = s2.lower_bound(3);
    auto ub = s2.upper_bound(3);
    cout << "lower_bound(3) em s2: " << (lb != s2.end() ? to_string(*lb) : "N/A") << endl;
    cout << "upper_bound(3) em s2: " << (ub != s2.end() ? to_string(*ub) : "N/A") << endl;

    // equal_range
    auto range = s2.equal_range(4);
    cout << "equal_range(4) em s2: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
