#include <iostream>
using namespace std;

int main(){
    int n, s, m = 0; cin >> n >> s;
    int min = 0;

    for(int i = 0; i < n; i++){
        cin >> m;
        s += m;
        if(s < min){
            min = s;
        }
  }

  cout << s << endl;

    return 0;
}