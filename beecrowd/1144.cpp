#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    for(long long int i = 1; i < N+1; i++){
        cout << i << " " << i*i << " " <<  i*i*i << endl;
        cout << i << " " << i*i+1 << " " << i*i*i+1 << endl;
    }

    return 0;
}