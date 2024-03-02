#include <stdlib.h>
#include <stdio.h>

void silnia(int liczby[], int rozmiar);

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    silnia(array, 10);
    
    return 0;
}

void silnia(int liczby[], int rozmiar){
    for(int i = 0; i < rozmiar; i++){ //przechodzi po tablicy
        int wynik = 1;
        for(int j = 1; j <= liczby[i]; j++){//oblicza silnie
            wynik*=j;
        }
        printf("%d\n", wynik);
    }
}
