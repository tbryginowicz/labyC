#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    FILE *fp;
    char * line = NULL;
    fp = fopen("input2.txt", "r");
    int sum = 0;
    size_t len = 0;
    size_t read;
    int red = 0;
    int green = 0;
    int blue = 0;
    int limitRed = 12;
    int limitGreen = 13;
    int limitBlue = 14;
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    int id = 0;
    int suma = 0;
    char *colors[] = {"red", "green", "blue"};
    int mocsuma = 0;
    while ((read = getline(&line, &len, fp)) != -1){
    id++;
    for(int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++){
        char *found = line;
        while((found = strstr(found, colors[i])) != NULL){
            int index = found - line;
            if (i == 0){
                if (isdigit(line[index-3])){
                    char numberStr[3] = {line[index-3], line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > red){
                        red = number;
                    }
                }else{
                    char numberStr[2] = {line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > red){
                        red = number;
                    }
                }
            }
            else if (i == 1){
                if (isdigit(line[index-3])){
                    char numberStr[3] = {line[index-3], line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > green){
                        green = number;
                    }
                }else{
                    char numberStr[2] = {line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > green){
                        green = number;
                    }
                }
            }
            else if (i == 2){
                if (isdigit(line[index-3])){
                    char numberStr[3] = {line[index-3], line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > blue){
                        blue = number;
                    }
                }else{
                    char numberStr[2] = {line[index-2], '\0'};
                    int number = atoi(numberStr);
                    if (number > blue){
                        blue = number;
                    }
                }
            }
            found++;
        }
    }
    if(red <= limitRed && blue <= limitBlue && green <= limitGreen){
        suma += id;
    }
    int moc = red*green*blue;
    mocsuma += moc;
    red = 0;
    green = 0;
    blue = 0;
}

    printf("\nSUMA: %d\n", suma);
    printf("\nSUMA MOCY: %d\n",mocsuma);
    return 0;
}