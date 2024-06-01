#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;

    int list[n];{for(int i = 0; i < n; i++){list[i]= i+1;}}

    for(int i = 0; i < n; i++){cout << list[i] << " ";}{cout << "\n";}

    random_shuffle(list, list + n);

    for(int i = 0; i < n; i++){cout << list[i] << " ";}{cout << "\n";}
    return 0;
}


