#include <stdio.h>
#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) {
        return 0;
    }

    int *candies = (int*)malloc(ratingsSize * sizeof(int));
    
    if (candies == NULL) {
        return -1;
    }

    for (int i =0; i < ratingsSize; i++) {
        candies[i] = 1;
    }

    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
            candies[i] = candies[i+1] + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < ratingsSize; i++) {
        sum += candies[i];
    }

    free(candies);
    return sum;
}


int main() {
    int ratings[] = {1,0,2};
    int size = sizeof(ratings) / sizeof(ratings[0]);
    printf("%d\n", candy(ratings, size));
    return 0;
}