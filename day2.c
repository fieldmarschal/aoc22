#include<stdio.h>
#define LEN 5001
//A X 1
//B Y 2 Created by Julius on 02.12.2022.
//C Z 3


void day2(void){
    int sum = 0;
    FILE *inputf;
    char temp1[10];
    char inputc[LEN];
    int i;

    inputf = fopen("day2input.txt","r");
    if(inputf != NULL){
        for(i = 0; i < LEN-1; i += 2) {
            fgets(temp1, 10, inputf);
            inputc[i] = temp1[0];
            inputc[i + 1] = temp1[2];

            printf("%s", temp1);
        }

        for(i = 0; i < LEN-1; i += 2) {
            if(inputc[i+1] == 'X'){
                if(inputc[i] == 'A') inputc[i+1] = 'Z';
                if(inputc[i] == 'B') inputc[i+1] = 'X';
                if(inputc[i] == 'C') inputc[i+1] = 'Y';
            }else if(inputc[i+1] == 'Y'){
                if(inputc[i] == 'A') inputc[i+1] = 'X';
                if(inputc[i] == 'B') inputc[i+1] = 'Y';
                if(inputc[i] == 'C') inputc[i+1] = 'Z';
            }else if(inputc[i+1] == 'Z'){
                if(inputc[i] == 'A') inputc[i+1] = 'Y';
                if(inputc[i] == 'B') inputc[i+1] = 'Z';
                if(inputc[i] == 'C') inputc[i+1] = 'X';
            }
        }

        for(i = 0; i < LEN-1; i += 2) {
            if(inputc[i+1] == 'X'){
                sum++;
            }
            if(inputc[i+1] == 'Y'){
                sum += 2;
            }
            if(inputc[i+1] == 'Z'){
                sum += 3;
            }
            if((inputc[i]=='A'&&inputc[i+1]=='X') ||
                (inputc[i]=='B'&&inputc[i+1]=='Y') ||
                (inputc[i]=='C'&&inputc[i+1]=='Z')){
                sum += 3;
            }
            if((inputc[i]=='A'&&inputc[i+1]=='Y') ||
                (inputc[i]=='B'&&inputc[i+1]=='Z') ||
                (inputc[i]=='C'&&inputc[i+1]=='X')){
                sum += 6;
            }
        }
        printf("\n%d", sum);
    }else{
        fprintf(stderr, "Fehler");
    }
    fclose(inputf);
}