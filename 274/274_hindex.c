#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
        return (*(int*)b - *(int*)a);
    }

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), compare);
    for (int i = 0; i < citationsSize; i++) {
            if (citations[i] < i + 1) {            
                return i;
            }
    }
    return 0;
}

int main() {
    int citations[] = {3, 0, 6, 1, 5};
    printf("%d", hIndex(citations, 5));
    return 0;
}