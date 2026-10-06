#include <stdbool.h>
bool into(char* suite, char c, int l, int n){
    int found = 0;
    for (int i = 0; i<l;i++){
        if (c == suite[i]){
            found++;
            if (n == found){
                return true;
            }
        }
    }
    return false;
}