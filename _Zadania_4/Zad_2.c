/*
**Cel:** Napisz funkcję rekurencyjną w języku C, która wykonuje wyszukiwanie binarne w posortowanej tablicy. Funkcja powinna zwracać indeks szukanego elementu lub wartość **`-1`**, jeśli element nie zostanie znaleziony w tablicy.

**Wymagania:**

1. Funkcja powinna przyjmować jako argumenty tablicę (wskaźnik na pierwszy element), lewy indeks, prawy indeks oraz wartość szukanego elementu.
2. Wyszukiwanie binarne polega na podziale tablicy na dwie części i sprawdzeniu, czy szukany element znajduje się w lewej czy prawej połowie tablicy, a następnie rekurencyjnym powtórzeniu procesu dla odpowiedniej części.
*/
#include<stdlib.h>
#include<stdio.h>

void bubbleSort(int array[], int size) {

  for (int j = 0; j < size - 1; ++j) {
    for (int i = 0; i < size - j - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void printArray(int array[], int size){
    printf("[");
    for(int i = 0; i < size - 1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}
int binarySearch(int array[],int value, int left, int right){
    if(left < right){
        bubbleSort(array,right);
        if(array[(left + right)/2] == value){
            return (left + right)/2;
        }else if(array[(left + right)/2] > value){
            return binarySearch(array, value, left, (left+right)/2);
        }else{
            return binarySearch(array, value, (left+right)/2, right);
        }
    }else{
        return -1;
    }
}

int main(){

    int arr[] = {1,2,213,32,5,65,76,457,8,21,54,92,96,90,21,63,78,49};
    bubbleSort(arr,18);
    printArray(arr,18);

    printf("\nINDEX 76: %d", binarySearch(arr,76,0,18));
    printf("\nINDEX 2: %d", binarySearch(arr,2,0,18));
    printf("\nINDEX 32: %d", binarySearch(arr,32,0,18));
    printf("\nINDEX 9999: %d\n\n", binarySearch(arr,999,0,18));
    return 0;
}