#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> list_1,list_2;
    list<int>:: iterator it;

    list_1.push_back(1);
    list_1.push_back(1);
    list_1.push_back(1);
    list_1.push_back(1);
    
    list_2.push_back(2);
    list_2.push_back(2);
    list_2.push_back(2);
    list_2.push_back(2);

    list_1.merge(list_2);

    for(it = list_1.begin(); it !=list_1.end(); it++){
        cout << *it << endl;
    }
}