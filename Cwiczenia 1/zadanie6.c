#include <stdlib.h>
#include <stdio.h>

int main() {

    int g1 = 0; //Wynik gracza 1
    int g2 = 0; //Wynik gracza 2

    char i1[7]; //input gracza 1
    char i2[7]; //input gracza 2

    int isRunning = 1;
    printf("Mozliwe komendy: papier, kamien, nozyce, wynik, stop");
    while (isRunning == 1){
        printf("Ruch gracza 1: ");
        scanf("%s",g1);
        printf("Ruch gracza 2: ");
        scanf("%s",g2);
        switch (g1){
            case "kamien":
                /* code */
                break;
            case "papier":
               /* code */
               break;
        }

    } 

    return 0;
}
