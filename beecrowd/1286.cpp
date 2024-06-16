#include <bits/stdc++.h>
using namespace std;

typedef struct pedido {
    int tempo;
    int quantidade;

    pedido() : tempo(0), quantidade(0) {}
    pedido(int t, int q) : tempo(t), quantidade(q) {}
} pedido;

int main() {
    int n, max, time, quant;
    vector<pedido> pedidos;
    while (cin >> n && n != 0) {
        cin >> max;
        for (int i = 0; i < n; i++) {
            cin >> time >> quant;
            pedidos.push_back(pedido(time, quant));
        }

        std::sort(pedidos.begin(), pedidos.end(), [](const pedido& a, const pedido& b) {
            return a.tempo < b.tempo;
        });

        for (const auto& p : pedidos) {
            cout << p.tempo << " " << p.quantidade << endl;
        }

        pedidos.clear();
        cout << endl;
    }

    return 0;
}
