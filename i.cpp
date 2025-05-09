#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int> map;
    int num, size = 0, sum=0, mediana;
    int t; cin >> t;
    while (t--)
    {
        while(cin >> num && num != 0) {
            if(num > 0) {
                map.insert(num);
                sum += num;
                size++;
            } else if(size % 2 != 0) {
                auto it = map.begin();
                advance(it, size / 2);  // Move o iterador para a mediana
                mediana = *it;
                map.erase(it);  // Remove a mediana
                size--;
                cout << mediana << "\n";
            } else {
                auto it = map.begin();
                cout << *it << "\n";  // Exibe o menor valor
                map.erase(it);  // Remove o menor valor
                size--;
            }
        }
    }

    return 0;
}
