#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char imie[30];
    float ocena;
}Student;

void studentSort(Student *arr, int n);

int main() {
    Student tab[5] = {{"Adam", 4.3f}, {"Jas", 2.0f}, {"Michal", 4.55f}, {"Dariusz", 3.95f}, {"Zosia", 5.0f}};
    studentSort(tab, 5);
    for (int i = 0; i < 5; i ++){
        printf("%s: %f", tab[i].imie, tab[i].ocena);
    }
    return 0;
}

void studentSort(Student *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].ocena < arr[j+1].ocena) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}