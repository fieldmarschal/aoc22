#include<stdio.h>
#include<string.h>

#define LEN 501
#define numt 9
//
// Created by Julius on 05.12.2022.
//

typedef struct towers {
    char crates[40];
} towers;

typedef struct moves {
    int count, start, end;
} moves;


void printCrates(towers *stack) {
    int i;
    for (i = 0; i < numt; i++) {
        printf("%s\n", stack[i].crates);
    }
}

void part1_5(towers *listt, moves *listm) {
    int o, i, len1, len2;

    for (i = 0; i < LEN; i++) {
        for (o = 0; o < listm[i].count; o++) {
            len1 = (int) strlen(listt[listm[i].end - 1].crates);
            len2 = (int) strlen(listt[listm[i].start - 1].crates);

            if (len2 != 0) {
                printf("len1: %d | len2: %d\n", len1, len2);
                listt[listm[i].end - 1].crates[len1] = listt[listm[i].start - 1].crates[len2 - 1];
                listt[listm[i].end - 1].crates[len1 + 1] = '\0';
                listt[listm[i].start - 1].crates[len2 - 1] = '\0';
            }

        }
        //printf("test");
        //printCrates(listt);
    }
    printCrates(listt);
}


void part2_5(void) {

}

void day5(void) {
    FILE *inputf;
    char temp1[40];
    towers listt[numt];
    moves listm[LEN];
    int i, o;

    inputf = fopen("day5inputtest.txt", "r");

    if (inputf == NULL) {
        printf("NULL");
    } else {
        for (i = 0; i < numt; i++) {
            strcpy(listt[i].crates, "");
        }
        for (i = 0; i < 8; i++) {
            char stack[10];
            char test;
            fgets(temp1, 40, inputf);
            for (o = 0; o < numt; o++) {
                if (64 < temp1[1 + (4 * o)] && temp1[1 + (4 * o)] < 91) {
                    strcpy(stack, listt[o].crates);
                    test = temp1[1 + (4 * o)];
                    strcpy(listt[o].crates, &test);
                }
            }
        }

        printCrates(listt);
        printf("\n\n");

        i = 0;
        while (fscanf(inputf, "move %d from %d to %d\n", &listm[i].count, &listm[i].start, &listm[i].end) != EOF) {
            //printf("move %d from %d to %d\n", listm[i].count, listm[i].start, listm[i].end);
            i++;
        }
    }
    part1_5(listt, listm);
    fclose(inputf);
}