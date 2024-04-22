#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){

    FILE *fp;
    char line[1024];
    fp = fopen("input.txt", "r");
    int sum = 0;
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL){
        char first = '\0';
        char last = '\0';
        int firstWordNumberIndex = 999;
        int lastWordNumberIndex = -1;
        char firstWordNumber = '\0';
        char lastWordNumber = '\0';
        for(int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++){
                char *found = strstr(line, nums[j]);
                if (found != NULL) {
                    int index = found - line;
                    if (index < firstWordNumberIndex) {
                        firstWordNumberIndex = index;
                        firstWordNumber = '0' + j;
                    }
                    if (index > lastWordNumberIndex) {
                        lastWordNumberIndex = index;
                        lastWordNumber = '0' + j;
                    }
                } 
            }
        first = firstWordNumber;
        last = lastWordNumber;
        for (int i = 0; i<strlen(line); i++){
            if (isdigit(line[i])){
                if(first == '\0' || i < firstWordNumberIndex){
                    first =  line[i];
                    firstWordNumberIndex = i;
                }

                if(last == '\0' || i > lastWordNumberIndex){
                    last = line[i];
                    lastWordNumberIndex = i;
                }
            }
        }
        char numberStr[3] = {first, last, '\0'};
        int number = atoi(numberStr);
        sum+= number;
        
    }
    printf("\n\n%d\n", sum);
    return 0;
}