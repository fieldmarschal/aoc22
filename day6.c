#include<stdio.h>
#include<string.h>

#define LEN 4100

//
// Created by Julius on 06.12.2022.
//
void part1_6(const char *input) {

    char output[5];
    strcpy(output, "");
    int i, sol = 0;
    output[0] = ' ';
    output[1] = input[0];
    output[2] = input[1];
    output[3] = input[2];
    output[4] = '\0';
    for (i = 3; i < LEN; i++) {
        output[0] = output[1];
        output[1] = output[2];
        output[2] = output[3];
        output[3] = input[i];
        if (output[0] != output[1] && output[0] != output[2] && output[0] != output[3] &&
            output[1] != output[2] && output[1] != output[3] && output[2] != output[3]) {
            sol = i;
            break;
        }
    }
    printf("Part1: %d\n", sol + 1);

}

part2_6(const char *input) {
    char output[15];
    strcpy(output, "");
    int i, o, p, c = 0, sol = 0;

    output[0] = ' ';
    output[1] = input[0];
    output[2] = input[1];
    output[3] = input[2];
    output[4] = input[3];
    output[5] = input[4];
    output[6] = input[5];
    output[7] = input[6];
    output[8] = input[7];
    output[9] = input[8];
    output[10] = input[9];
    output[11] = input[10];
    output[12] = input[11];
    output[13] = input[12];
    output[14] = '\0';

    for (i = 13; i < LEN; i++) {
        output[0] = output[1];
        output[1] = output[2];
        output[2] = output[3];
        output[3] = output[4];
        output[4] = output[5];
        output[5] = output[6];
        output[6] = output[7];
        output[7] = output[8];
        output[8] = output[9];
        output[9] = output[10];
        output[10] = output[11];
        output[11] = output[12];
        output[12] = output[13];
        output[13] = input[i];
        for (o = 0; o < 14; o++) {
            for (p = 0; p < 14; p++) {
                if (o != p) {
                    if (output[o] != output[p]) {
                        c++;

                    } else {
                        c = 0;
                        o = 14;
                        break;
                    }
                }
            }
        }
        if (c == 14 * 13) {
            sol = i;
            printf("r");
            break;
        }
    }

    printf("Part2: %d", sol + 1);
}

void day6(void) {
    FILE *inputf;
    char input[LEN];

    inputf = fopen("C:\\Users\\Julius\\ClionProjects\\aoc22\\day6input.txt", "r");
    fgets(input, LEN, inputf);
    part1_6(input);
    part2_6(input);

}