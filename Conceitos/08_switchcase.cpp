#include <iostream>

using namespace std;

int main() {
    int val;
    cout << "Selecione uma cor\n";
    cout << "[1] Verde,  [2] Azul, [3] Vermelho \n";

    cin >> val;

    switch(val) {
        case 1:
            cout << "Cor selecionada: Verde \n";
            break;
        case 2:
            cout << "Cor selecionada: Azul \n";
            break;
        case 3:
            cout << "Cor selecionada: Vermelho \n";
            break;
        default:
            cout << "Valor selecionado inválido\n";
            break;
    }

    cout << "\n programa finalizado \n";

    return 0;
}
