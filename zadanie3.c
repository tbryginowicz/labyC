#include <stdlib.h>
#include <stdio.h>

int silnia(int tab[], int size);

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    printf("%d",silnia(array, sizeof(array)/sizeof(array[0])));

    return 0;
}

int silnia(int tab[], int size){
    int wynik = 1;
    for(int i = 0; i < size; i++){
        wynik *=tab[i];
    }
    return wynik;
}