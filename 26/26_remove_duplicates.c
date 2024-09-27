#include <stdio.h>

/**
 * Remove duplicates from a sorted array.
 *
 * @param nums The array to modify
 * @param numsSize The size of the array
 * @return The new size of the array with duplicates removed
 */
 
int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    // j starts at 1 because we are comparing each element with the previous one,
    // so we start with the second element and compare it with the first one.
    for (int j=1; j<numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}


int main() {
    int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 4, 4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int size = removeDuplicates(nums, len);
    printf("%d\n", size);
}