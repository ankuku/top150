#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculate the minimum number of candies given to children in a line.
 *
 * Each child must have at least one candy.
 * A child with a higher rating than his neighbors must have more candies.
 *
 * @param ratings The ratings of the children in a line.
 * @param ratingsSize The number of children in a line.
 * @return The minimum number of candies given to children in a line.
 */
int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) {
        return 0;
    }

    int *candies = calloc(ratingsSize, sizeof(int));
    if (candies == NULL) {
        // Handle allocation failure if needed
        return -1;
    }

    candies[0] = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
    }

    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) { 
            candies[i] = candies[i + 1] + 1;
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