#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float n1, n2, n3, n4, n5;
    cin >> n1 >> n2 >> n3 >> n4;
    
    float media = (n1*2 + n2*3 + n3*4 +n4)/10;
    cout << fixed << setprecision(1);
    cout << "Media: " << media << endl;
    
    if(media >= 7){
        cout << "Aluno aprovado." << endl;
    }else if(media >= 5){
        cout << "Aluno em exame." << endl;
        cin >> n5;

        float media1 = (n5 + media)/2;
        cout << "Nota do exame: " << n5 << endl;

        
        if(media >= 5){
            cout << "Aluno aprovado." << endl;
            cout << "Media final: " << media1 << endl;
        }else{
            cout << "Aluno reprovado." << endl;
        }
    }else{
        cout << "Aluno reprovado." << endl;
    }

    return 0;
}