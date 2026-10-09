#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

char* generation();
bool into(char* suite, char c, int l, int n);
void resetArray(int* array, int l);


int main(int ac, char** av){


    char* code = generation();
    int attempts = 10;
    for (int i = 0; i<ac-1;i++){
        if (strcmp(av[i],"-c") == 0){
            if (strlen(av[i+1])==4){
                code = av[i+1];
            }
        }
        if (strcmp(av[i],"-t") == 0){
            attempts = atoi(av[i+1]);
        }
    }
    if (attempts <= 0){
        attempts = 10;
    }


    int bienP = 0;
    int malP = 0;
    char essai = 0;
    int i = 0;
    int* repetitions = calloc(9,sizeof(int));


    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    while (true){
        read(0,&essai,1);
        if (essai == 0){
            return 0;
        }
        if (code[i] == essai){
            bienP++;
            repetitions[essai-'0']++;

        } else if (into(code,essai,4,repetitions[essai-'0']+1)){
            malP++;
            repetitions[essai-'0']++;
        }
        i++;
        if ((essai == '\n' && i!=5)||!into("012345678\n",essai,10,1)){
            printf("Wrong input!\n");
            bienP = 0;
            malP = 0;
            i = 0;
            resetArray(repetitions,8);
            while (essai != '\n'){
                read(0,&essai,1);
            }
            essai = 0;
        } else if (essai == '\n'){
            attempts--;
            if (bienP == 4){
                printf("Congratz! You did it!\n");
                free(repetitions);
                return 0;
            }
            if (attempts == 0){
                printf("You lost, the code was %s",code);
                free(repetitions);
                return 0;
            }
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n",bienP,malP);
            essai = 0;
            bienP = 0;
            malP = 0;
            i = 0;
            resetArray(repetitions,8);
        }
    }
}