#include<stdlib.h>
#include<stdio.h>

int main(){

    int tab[] = {0,1,2,3,4,5,6,7,8,9};

    int *pointer = &tab[0];

    while (pointer < tab + sizeof(tab)/sizeof(tab[0])){
        printf("%d\n", *pointer);
        pointer++;
    }

}