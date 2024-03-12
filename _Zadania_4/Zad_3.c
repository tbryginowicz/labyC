#include<stdlib.h>
#include<stdio.h>

void printArray(int array[], int size){
    printf("[");
    for(int i = 0; i < size - 1; i++){
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size-1]);
}

void swap(int arr[], int i, int k){
    int temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
}

void permutations(int arr[], int start, int size){
    if(start == size-1){
        printArray(arr,size);
    }
    for (int i = start; i < size; i++){
        swap(arr, start,i);
        permutations(arr,start+1, size);
        swap(arr, start, i);
    }
    
}

int main(){

    int arr[] = {1,2,3};

    permutations(arr,0,3);

    return 0;
}