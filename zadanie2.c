#include <stdlib.h>
#include <stdio.h>

float avg(int tab[], int size);

int main() {
    int grades[5][6] = {{2,4,5,6,2}, {5,5,3,5,2,3}};
    printf("Srednia ocen z matematyki: %f \nSrednia ocen z fizyki: %f", avg(grades[0],5), avg(grades[1],6));

    return 0;
}

float avg(int tab[], int size){
    int i;
    float sum = 0;
    for (i = 0;i < size; i++){
        sum += (float)tab[i];
    }
    return sum/i;
}