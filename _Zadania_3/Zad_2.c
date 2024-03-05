#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    int x,y;
    int** tab;
    printf("Podaj pierwszą liczbe: ");
    scanf("%d", &x);
    printf("\nPodaj drugą liczbę: ");
    scanf("%d", &y);
    printf("\n");
    tab = (int**)malloc(y * sizeof(int*));

    for (int i = 0; i < y; i++){
        tab[i] = (int*)malloc(x * sizeof(int));
    }
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            tab[i][j] = rand() %11;
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < x; i++){
        free(tab[i]);
    }
    free(tab);

    return 0;
}