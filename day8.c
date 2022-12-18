#include<stdio.h>

#define LEN 100

//
// Created by Julius on 09.12.2022.
//
void day8(void) {
    FILE *inputf;
    int input[100][100], output[100][100], i = 0, o = 0, p;

    inputf = fopen("day8input.txt", "r");
    while ((p = fgetc(inputf)) != EOF) {
        if (p != '\n') {
            input[i][o] = p;
            o++;
        } else {
            i++;
            o = 0;
        }
    }

    for (i = 0; i < LEN; i++) {
        output[0][i] = 1;
        output[i][0] = 1;
        output[99][i] = 1;
        output[i][99] = 1;
    }

    for (i = 1; i < LEN - 1; i++) {
        for (o = 1; o < LEN - 1; o++) {
            
        }
    }
}