#include <stdio.h>
#include <string.h>
#define LEN1 300
#define LEN2 55

//
// Created by Julius on 03.12.2022.
//

char inputc1[LEN1][LEN2];
char inputc2[LEN1][LEN2];
int i = 0, sum = 0, len,o;
char *ret;

void part1(void){
    for(i = 0; i < LEN1; i++){
        len = strlen(inputc1[i]) - 1;
        for(o = len / 2; o < len; o++){
            inputc2[i][o-len / 2] = inputc1[i][o];
            inputc1[i][o] = '\0';
        }
        ret = strpbrk(inputc1[i], inputc2[i]);

        if(*ret < 95){
            sum += *ret-38;
        } else {
            sum += *ret-96;
        }
    }
}

void part2(void){
    char *ret3;
    for(i = 0; i < LEN1; i+=3){
        ret = strpbrk(inputc1[i], inputc1[i+1]);
        ret3 = strpbrk(ret, inputc1[i+2]);
        if(*ret3 < 95){
            sum += *ret3-38;
        } else {
            sum += *ret3-96;
        }
    }
}

void day3(void){
    char temp1[LEN2];
    FILE *inputf;
    inputf = fopen("day3input.txt", "r");
    while(fgets(temp1, LEN2, inputf)!= NULL){
        strcpy(inputc1[i], temp1);
        i++;
    }
    part2();
    printf("%d", sum);
    fclose(inputf);
}