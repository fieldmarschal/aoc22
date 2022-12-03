#include<stdio.h>
#include<stdlib.h>
#define LEN 2500
//
// Created by Julius on 01.12.2022.
//

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void day1(void){
    FILE *inputf;
    char temp1[10];
    char* temp2[10];
    int inputi[LEN], outputi[LEN];
    int i, o = 0, temp = 0;
    inputf = fopen("day1input.txt","r");
    if(inputf != NULL){
        for(i=0;i<LEN;i++){
            fgets(temp1,6,inputf);
            inputi[i] = strtol(temp1,temp2,10);
        }
        outputi[o] = 0;
        for(i = 0; i < 2241; i++) {
            if (inputi[i] != 0) {
                outputi[o + 1] = 0;
                outputi[o] += inputi[i];

            }else o++;
        }

        for(o = 0; o < LEN; o++){
         if(outputi[o] > temp){
             temp = outputi[o];
         }
        }

        qsort(outputi, LEN, sizeof(int), cmpfunc);


        for(o = 0; o < LEN; o++){
            printf("%d\n", outputi[o]);
        }

    }else{
       fprintf(stderr,"Input nicht gelesen!");
    }
}