#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

char* generation();
bool into(char* suite, char c, int l);


int main(int ac, char** av){
    char* code = generation();
    int attempts = 10;
    for (int i = 0; i<ac-1;i++){
        if (strcmp(av[i],"-c") == 0){
            code = av[i+1];
        }
        if (strcmp(av[i],"-t") == 0){
            attempts = atoi(av[i+1]);
        }
    }

    int bienP = 0;
    int malP = 0;
    char essai = '_';
    int i = 0;
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    while (attempts>0){
        read(0,&essai,1);
        if (code[i] == essai){
            bienP++;
        } else if (into(code,essai,4)){
            malP++;
        }
        i++;
        if (essai == '\n'){
            if (bienP == 4){
                printf("Congratz! You did it!\n");
                return 0;
            }
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n",bienP,malP);
            bienP = 0;
            malP = 0;
            i = 0;
            attempts--;
        }
        if (!into("012345678\n",essai,10)){
            printf("Wrong input!\n");
            bienP = 0;
            malP = 0;
            i = 0;
            while (essai != '\n'){
                read(0,&essai,1);
            }
        }
    
    }
    return 0;

}