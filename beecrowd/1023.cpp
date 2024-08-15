#include <bits/stdc++.h>
using namespace std;

int numCidade = 0;
bool primeiro = true;
bool first = true;


void solve() {
    numCidade++;
    int x, y, n;
    int numPessoas = 0;
    int numConsumo = 0;
    vector<int> cdd (201, 0);

    cin >> n;
    if (n == 0) {
        return;
    }
    if (!primeiro) {
        cout << "\n";
    }
    while (n--) {
        cin >> x >> y;
        numPessoas += x;
        numConsumo += y;
        cdd[y/x] += x;
    }


    cout << "Cidade# " << numCidade << ":\n";
    
    for (int i = 0; i < 201; ++i){
        if (cdd[i] > 0)
        {
            if (first)
                first = false;
            else
                cout << ' ';

            cout << cdd[i] << '-' << i;
        }
    }

    double consumo_medio = floor(100.0 * numConsumo / numPessoas) / 100.0;
    cout << "\nConsumo medio: " << setprecision(2) << fixed << consumo_medio << " m3." << endl;
    primeiro = false;
    solve();
}

int main() {
    solve();
    return 0;
}
