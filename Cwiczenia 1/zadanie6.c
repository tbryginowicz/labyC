#include <stdlib.h>
#include <stdio.h>

int main() {

    int g1 = 0; //Wynik gracza 1
    int g2 = 0; //Wynik gracza 2

    char i1[7]; //input gracza 1
    char i2[7]; //input gracza 2

    int isRunning = 1;
    printf("Dostepne polecenia: papier, kamien, nozyce, wynik, stop\n");
    while (isRunning == 1){
        printf("Ruch gracza 1: ");
        scanf("%s",i1);
        printf("Ruch gracza 2: ");
        scanf("%s",i2);
        if (strcmp(i1, "kamien") == 0 && strcmp(i2, "nozyce") == 0) {
            printf("Gracz 1 wygrywa!\n");
            g1++;
        } else if (strcmp(i1, "kamien") == 0 && strcmp(i2, "papier") == 0) {
            printf("Gracz 2 wygrywa!\n");
            g2++;
        } else if (strcmp(i1, "papier") == 0 && strcmp(i2, "kamien") == 0) {
            printf("Gracz 1 wygrywa!\n");
            g1++;
        } else if (strcmp(i1, "papier") == 0 && strcmp(i2, "nozyce") == 0) {
            printf("Gracz 2 wygrywa!\n");
            g2++;
        } else if (strcmp(i1, "nozyce") == 0 && strcmp(i2, "papier") == 0) {
            printf("Gracz 1 wygrywa!\n");
            g1++;
        } else if (strcmp(i1, "nozyce") == 0 && strcmp(i2, "kamien") == 0) {
            printf("Gracz 2 wygrywa!\n");
            g2++;
        } else if (strcmp(i1, "wynik") == 0 || strcmp(i2, "wynik") == 0) {
            printf("Gracz 1: %d punktow, Gracz 2: %d punktow\n", g1, g2);
        } else if (strcmp(i1, "stop") == 0 || strcmp(i2, "stop") == 0) {
            printf("Gracz 1: %d punktow, Gracz 2: %d punktow\nKONIEC GRY!", g1, g2);
            isRunning = 0;
        } else if (strcmp(i1, i2) == 0) {
            printf("Remis!\n");
        } else {
            printf("Niepoprawny ruch!\n");
        }
        
    } 

    return 0;
}
