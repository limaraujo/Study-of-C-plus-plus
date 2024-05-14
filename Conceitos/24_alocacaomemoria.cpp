#include <iostream>
#include <stdio.h>  //para a função gets
#include <stdlib.h> //para função malloc

using namespace std;

int main(){
    char *vnome;
    vnome = (char *)malloc(sizeof(char)+1);

    gets(vnome);

    cout << vnome;

    return 0;
}