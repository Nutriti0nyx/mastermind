#include <stdbool.h>
bool into(char* suite, char c, int l){
    for (int i = 0; i<l;i++){
        if (c == suite[i]){
            return true;
        }
    }
    return false;
}