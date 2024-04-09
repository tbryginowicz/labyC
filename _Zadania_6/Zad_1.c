#include<stdlib.h>
#include<stdio.h>

union Unia{
    int integer;
    float przecinek;
    char znak;
};

int main(){


    union Unia unia;
    unia.integer = 10;
    printf("%d\n", unia.integer);
    unia.przecinek = 3.14f;
    printf("%f\n", unia.przecinek);
    unia.znak = 'e';
    printf("%c\n",unia.znak);
    return 0;
}