#include <stdlib.h>
#include <stdio.h>

int silnia(int liczba);

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++){
        printf("%d \n",silnia(array[i]));
    }
    
    return 0;
}

int silnia(int liczba){
    int wynik = 1;
    for(int i = 1; i <= liczba; i++){
        wynik*=i;
    }
    return wynik;
}
