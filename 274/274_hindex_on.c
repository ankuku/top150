#include <stdio.h>
#include <stdlib.h>

int hIndex(int* citations, int citationsSize) {
    // Step 1: Count the number of each citation
    int* freq = (int*)calloc(citationsSize + 1, sizeof(int));
    
    // Step 2: Count the citations
    for (int i = 0; i < citationsSize; i++) {
        (citations[i] >= citationsSize) ? freq[citationsSize]++ : freq[citations[i]]++;
    }

    // Step 3: Sum citations from the end to calculate the H-index
    int total = 0;
    for (int i = citationsSize; i >= 0; i--) {
        total += freq[i];  // Total papers with i or more citations
        if (total >= i) {
            free(freq);  // Free the dynamically allocated memory
            return i;
        }
    }
    free(freq);  // Free the dynamically allocated memory
    return 0;
}

int main() {
    int citations[] = {3, 0, 6, 1, 5};
    int size = sizeof(citations) / sizeof(citations[0]);
    int h_index = hIndex(citations, size);
    printf("%d", h_index);
}
