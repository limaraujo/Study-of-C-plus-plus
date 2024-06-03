//sfold e fold

#include <bits/stdc++.h>
using namespace std;

//sfold
    
int hashing(string k,int size){
    int intLength = (k.size() / 4);
    int sum = 0;
    for(int i = 0; i < intLength; i++){
        string sub = k.substr(i*4,4);
        int mult = 1;

        for(int j = 0; j < 4; j++){
            sum += + sub[j]*mult;
            mult *= 256;

        }
    }
    string sub = k.substr(intLength * 4);
    int mult = 1;
    for(int j = 0; j < sub.size(); j++){
            sum += + sub[j] * mult;
            mult *= 256;
    }

    return abs(sum) % size;
}

//fold
    int h(string& k, int size){
        int s = k.length(), sum = 0;
        for (int i = 0; i < s; ++i) {
            sum += k[i];
        }
        return sum % size;
    }