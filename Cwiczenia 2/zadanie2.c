#include <stdlib.h>
#include <stdio.h>

void doubleFloat(float *f);
int main() {
    float liczba = 25.3f;
    float * pliczba = &liczba;
    doubleFloat(pliczba);
    printf("%.2f", liczba);
    return 0;
}

void doubleFloat(float *f){
    *f *=2;
}