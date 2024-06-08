#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x1, y1, x2, y2, dx, dy, mov;
    cin >> x1 >> y1 >> x2 >> y2;
    
    while(x1 != 0 && y1 != 0 && x2 != 0 && y2 !=0){
        if(x1 == x2 && y1 == y2){
            mov = 0;
        }else{
            dx = abs(x1 - x2);
            dy = abs(y1 - y2);
            if( dx == dy || x1 == x2 || y1 == y2 ){
            mov = 1;
            }else{
            mov =  2;
            }
        }

        cout << mov << endl;
        cin >> x1 >> y1 >> x2 >> y2;
    }
}