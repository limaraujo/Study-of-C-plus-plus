#include <bits/stdc++.h>
using namespace std;

int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    int n; cin >> n;
    while(n--){
        string num; cin >> num;
        int numLeds = 0;

        for(char& c : num){
            numLeds += leds[c - '0'];
        }

        cout << numLeds << " leds\n";
    }
    return 0;
}
