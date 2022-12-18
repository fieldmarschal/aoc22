#include<stdio.h>
#include<string.h>
#define LEN 1000
//
// Created by Julius on 04.12.2022.
//
typedef struct ids{
    int begin1;
    int end1;
    int begin2;
    int end2;
} ids;

ids input[LEN];
int sum = 0;

void part1_4(void){
    int i;
    for(i = 0; i < LEN; i++){
        if(input[i].begin2 <= input[i].begin1 && input[i].end1 <= input[i].end2){
            sum++;
        }else if(input[i].begin1 <= input[i].begin2 && input[i].end2 <= input[i].end1){
            sum++;
        }
    }
}

void part2_4(void){
    int i;
    for(i = 0; i < LEN; i++){
        if(input[i].begin1 <= input[i].begin2 && input[i].begin2 <= input[i].end1 ||
            input[i].begin1 <= input[i].end2 && input[i].end2 <= input[i].end1){
            sum++;
        }else if(input[i].begin2 <= input[i].begin1 && input[i].begin1 <= input[i].end2 ||
            input[i].begin2 <= input[i].end1 && input[i].end1 <= input[i].end2){
            sum++;
        }
    }
}

void day4(void){
    FILE *inputf;
    int i = 0;

    inputf = fopen("day4input.txt", "r");

    while(i<LEN){
       fscanf(inputf, "%d-%d,%d-%d", &input[i].begin1, &input[i].end1, &input[i].begin2, &input[i].end2);
       i++;
    }

    part2_4();
    printf("%d", sum);
    fclose(inputf);
}