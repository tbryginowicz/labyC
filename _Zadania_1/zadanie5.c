#include <stdlib.h>
#include <stdio.h>

int policz(int liczba);

int main() {
    printf("%d",policz(25));
    return 0;
}
int policz(int liczba){
    if (liczba < 0) {
        return 0;
    }
    int suma = 0;
    for (int i = 0; i < liczba; i ++){
        if(i % 3 == 0 || i % 5 == 0){
            suma+=i;
        }
    }
    return suma;
}
