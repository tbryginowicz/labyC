#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *zero = "zero";
char *one = "one";
char *two = "two";
char *three = "three";
char *four = "four";
char *five = "five";
char *six = "six";
char *seven = "seven";
char *eight = "eight";
char *nine = "nine";

int main(){

    FILE *fp;
    char * line = NULL;
    fp = fopen("xd.txt", "r");
    int sum = 0;
    size_t len = 0;
    ssize_t read;
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }

    char *nums[] = {zero, one, two, three, four, five, six, seven, eight, nine};

    while ((read = getline(&line, &len, fp)) != -1){
        char first = '\0';
        char last = '\0';
        char temp1;
        char temp2;
        int firstWordNumberIndex = 999;
        int lastWordNumberIndex = -1;
        int firstWordNumber = -1;
        int lastWordNumber = -1;
        for(int j = 0; j < sizeof(nums) / sizeof(nums[0]); j++){
                char *found = strstr(line, nums[j]);
                if (found != NULL) {
                    int index = found - line;
                    if (index < firstWordNumberIndex) {
                        firstWordNumberIndex = index;
                        firstWordNumber = j;
                        temp1 = j - '0';
                    }
                    if (index > lastWordNumberIndex) {
                        lastWordNumberIndex = index;
                        lastWordNumber = j;
                        temp2 = j - '0';
                    }
                } 
            }
        for (int i = 0; i<strlen(line); i++){
            if(firstWordNumber != -1){
                first = '0' + firstWordNumber;
            }
            if (lastWordNumber != -1){
                last = '0' + lastWordNumber;
            }
            if isdigit(line[i]){
                //TODO: NIE DZIALA XDDDD NIE WIME OLOLOLOLOLOL
                if(first == '\0' || i < firstWordNumberIndex){
                    printf("LOL");
                    first =  '0' + line[i];
                    firstWordNumberIndex = i;
                    printf("A%cA", line[i]);
                }
                if(last == '\0'){
                    printf("XD");
                    last = line[i];
                }else if (lastWordNumber !=-1 && i> lastWordNumberIndex){
                    printf("HAHA");
                    last = lastWordNumber - '0';
                }
            }
        }
        char numberStr[3] = {first, last, '\0'};
            
        int number = atoi(numberStr);
        sum+= number;
        
    }
    printf("%d\n", sum);
    char xdd = '5';
    char lol = '6';
    char numberxdd[3] = {xdd, lol, '\0'};
    //printf("%d", atoi(numberxdd));
    return 0;
}