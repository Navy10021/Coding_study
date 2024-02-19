// Combination Masking given string : ABC -> #BC, A#C, AB#, ... ###
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void partition(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        printf("%s\n", path);
        return;
    }
    path[path_idx] = str[l];
    // include current char str[l]
    partition(str, l + 1, r, path, path_idx + 1);
    // Exclude current char as Masking
    path[path_idx] = '#';
    partition(str, l + 1, r, path, path_idx + 1);
}

void subsequnces(char *str){
    int length = strlen(str);
    char * path = (char*)malloc((length + 1) * sizeof(char));

    partition(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[100] = "ABCD";
    //scanf("%s", input);
    
    subsequnces(input);
    return 0;
}
