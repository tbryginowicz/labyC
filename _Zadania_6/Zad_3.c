#include <stdlib.h>
#include <stdio.h>

int dodaj(int a, int b){
    return a+b;
}
int odejmij(int a, int b){
    return a-b;
}
int pomnoz(int a, int b){
    return a*b;
}

int main(){

    int (*licz)(int, int);
    printf("Wpisz 0 zeby mnozyc, 1 zeby dodac, 2 zeby odjac: ");
    int x;
    scanf("%d", &x);
    printf("Wpisz dwie liczby po spacji: ");
    int a,b;
    scanf("%d %d", &a, &b);
    switch (x)
    {
    case 0:
        licz = &pomnoz;
        break;
    case 1:
        licz = &dodaj;
        break;
    case 2:
        licz = &odejmij;
        break;
    }
    printf("%d\n", (licz)(a,b));
    return 0;
}