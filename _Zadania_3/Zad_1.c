#include <stdlib.h>
#include <stdio.h>

int max(int num1, int num2){
    if(num1 > num2)
    {
        return num1;      
    }

    if(num2 >= num1)
    {
        return num2;
    }
}

int main() {
    int wysokosc, i, j;
    printf("Podaj wysokosc: ");
    scanf("%d", &wysokosc);
    int tab[wysokosc+1][wysokosc+1];

    for (i = 0; i<=wysokosc; i++){
        for (j = 0; j<i; j++){
            if(i == 0 || i == 1){
                tab[i][j] = 1;
            }
            else if(j == 0 || j == i){
                tab[i][j] = 1;
            }
            else{
                tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
            }
            printf("%d",tab[i][j]);
        }
        printf("\n");
    }
    /*
    a
    for (i = 0; i<=wysokosc; i++){
        for (j = 0; j<i; j++){
            printf("%d", tab[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}