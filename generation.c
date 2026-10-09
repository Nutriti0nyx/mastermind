#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>



//bool into(char* suite, char c, int l, int n);

/*char* generation(){
        char * code = malloc(5);
        code[0] = (rand() % 9)+'0';
        code[1] = (rand() % 9)+'0';
        code[2] = (rand() % 9)+'0';
        code[3] = (rand() % 9)+'0';
        code[4] = '\0';
        return code;
}*/


bool into(char* suite, char c, int l, int n);

char* generation(){
        char * code = malloc(5);
        code[0] = (rand() % 9)+'0';
        while (into(code,code[1],5,2)){
        code[1] = (rand() % 9)+'0';
        }
        while (into(code,code[2],5,2)){
        code[2] = (rand() % 9)+'0';
        }
        while (into(code,code[3],5,2)){
        code[3] = (rand() % 9)+'0';
        }
        code[4] = '\0';
        return code;
}

