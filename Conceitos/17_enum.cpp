#include <iostream>
using namespace std;

int main(){

    // estrutura/dado que agrupa valores(sequencia, geralmente) de inteiros constantes
    // esses valores são acessados pelos seu nomes, enumeradores.
    enum armas {
    fuzil=100,
    revolver=8,
    rifle=12,
    escopeta=1
    };
    
    armas armasSel;

    armasSel=rifle;

    cout<<armasSel;

    return 0;
}
