#include <stdlib.h>
#include <stdio.h>

int main() {
    int i = 1;
    int *pi = &i;

    *pi = 15;
    
    printf("%i",i);
    printf("\n");
    printf("%i",*pi);

    return 0;
}