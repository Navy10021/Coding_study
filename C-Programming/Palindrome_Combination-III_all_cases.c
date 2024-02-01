#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Combinatons-III : generate all palindromes by deleting and rearranging given words
int isPalindrome(char * str){
    int st = 0;
    int en = strlen(str) - 1;

    while(st < en){
        if (str[st] != str[en]){
            return 0;
        }
        st++;
        en--;
    }
    return 1;
}

int seen(char **arr, int arr_cnt, char * tgt){
    for (int i = 0; i < arr_cnt; i++){
        if (strcmp(arr[i], tgt)==0){
            return 1;
        }
    }
    return 0;
}

// Combination with repetition
void generateCombinations(char set[], int n, int k, char current[], int index, char**arr, int*arr_cnt, int used[]) {
    if (index == k) {
        if (!seen(arr, *arr_cnt, current)&&isPalindrome(current)){
            arr[(*arr_cnt)++] = strdup(current);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if(!used[i]){
            used[i] = 1;
            current[index] = set[i];
            generateCombinations(set, n, k, current, index + 1, arr, arr_cnt, used);
            used[i] = 0;
        }
    }
}

void combinations(char set[], int n, int k){
    
    char *current = (char*)malloc((k+1) * sizeof(char));
    current[k] = '\0';
    
    int arr_size = 1 << n;
    char **arr = (char **)malloc(arr_size * sizeof(char *));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = (char *)malloc((n + 1) * sizeof(char));
    }
    int arr_cnt = 0;
    
    // for no using element twice.
    int used[n];
    for (int i=0; i<n; i++){
        used[i] = 0;
    }
    
    generateCombinations(set, n, k, current, 0, arr, &arr_cnt, used);
    
    // Print the results
    for (int i = 0; i < arr_cnt; i++) {
        printf("%s, ", arr[i]);
        free(arr[i]); // Free memory for each string
    }
    free(arr);
    free(current);
}

int main() {
    //char set[] = {'A', 'B', 'B'};
    //int n = sizeof(set) / sizeof(set[0]);
    char set[100];
    scanf("%s", set);
    int n = strlen(set);
    //int k = 2; // Length of combinations
    //combinations(set, n, k);
    for (int k = 1; k <= n; k++){
        printf("{");
        combinations(set, n, k);
        printf("}\n");
    }
    
    return 0;
}