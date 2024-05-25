#include <bits/stdc++.h>
using namespace std;

int main (){
    int j = 8;
    while(j>0){
    string s;
    int x = 0;int o = 0;
    getline(cin,s);

    for(int i = 0; i < s.length(); i++){
        char c = s.at(i);
        if(c == 'X'){x++;}
        else{
            if(x <2){x = 0;}
            o++;
        }
    }
    if(x==2){cout << "Alice" << endl;}
    else if(o>=2 || x==3){cout <<"?"<<endl;}
    else{cout << "*"<<endl;}
        j--;
    }
}