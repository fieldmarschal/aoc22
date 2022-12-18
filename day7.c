#include<stdio.h>
#include<string.h>

#define LEN 370
//
// Created by Julius on 07.12.2022.
//

typedef struct folder {
    int size;
    char name[10];
} Directory;


typedef struct tree{
     struct tree *node;
     Directory dir;
}tree ;

void day7(void) {
    FILE *inputf;
    char input[25], trans[25];
    int i = 0;

    Directory dirs[LEN];

    inputf = fopen("day7input.txt", "r");

    while (fgets(input, 26, inputf)) {
        if (strncmp(input, "dir", 3) == 0) {
            sscanf(input, "dir %s", trans);
            strcpy(dirs[i].name, trans);
            dirs[i].size = 0;
            i++;
        }
    }
}
