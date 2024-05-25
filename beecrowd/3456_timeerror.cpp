#include <bits/stdc++.h>
using namespace std;
void mod7(string x){
    if(x.length() == 1 && x[0] - '0' < 9){
        cout << x << endl;
        return;}
    else{
        string n = ""; int r = 0;
        for(long long int i = 0; i<x.length(); i++){
            if( i !=  x.length()-1){
                n += x.at(i);
            }
            else{
                r = x.at(i) - '0';
            }
        }
        x = to_string(stoi(n) * 3 + r);
        if (x.length() != 1){
            cout << x << endl;}
        return mod7(x);
    }

}
int main(){
    string x; cin >> x;
    mod7(x);
    return 0;
}