#include <stdlib.h>
#include <string.h>
char* generation(){
        char * code = malloc(5);
        code[0] = (rand() % 9)+'0';
        code[1] = (rand() % 9)+'0';
        code[2] = (rand() % 9)+'0';
        code[3] = (rand() % 9)+'0';
        code[4] = '\0';
        return code;
}