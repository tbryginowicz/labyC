#include <stdlib.h>
#include <stdio.h>

int newton(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return newton(n - 1, k - 1) + newton(n - 1, k);
}

int main() {
    int wysokosc, i, j;
    printf("Podaj wysokosc: ");
    scanf("%d", &wysokosc);

    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", newton(i, j));
        }
        printf("\n");
    }

    return 0;
}