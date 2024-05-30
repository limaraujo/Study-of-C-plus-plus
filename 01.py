#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, v;
    cin >> e >> v;

    float h = e / (float)v;
    int H = e / v;
    int m = (h - H) * 60; 

    if(h + 19 < 24){
        cout << H + 19 << ":" << m << endl;
    }else{
        H = (H-5) %24;
        if(H <10){
            if(m >10){
                cout << "0" << H << ":" << m << endl;
            }
            else{
                cout << "0" << H << ":" << "0" << m << endl;
            }
        }
        else{
            if(m >10){
                cout << H << ":" << m << endl;
            }
            else{
                cout << H << ":" << "0" << m << endl;
            }
        }
    }
}
