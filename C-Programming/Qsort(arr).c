#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    const char *strings[] = {"Apple", "Orange", "Banana", "Grapes"};
    size_t numStrings = sizeof(strings) / sizeof(strings[0]);

    qsort(strings, numStrings, sizeof(strings[0]), compareStrings);

    // Display the sorted strings
    for (size_t i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}