#include <stdio.h>

/**
 * Remove duplicates from a sorted array in-place such that each unique element
 * appears at most twice. The relative order of the elements should be kept the same.
 *
 * @param nums The array to modify
 * @param numsSize The size of the array
 * @return The new size of the array with duplicates removed
 */
int removeDuplicates(int* nums, int numsSize) {
    // count is the number of times the current element has been seen
    int count = 1;
    // previous is the index of the previous element
    int previous = 0;
    // iterate through the array
    for (int current=1; current<numsSize; current++) {
        // if the current element is the same as the previous one
        if (nums[current] == nums[previous]) {
            // if we have seen this element less than two times, then keep it
            if (count < 2) {
                // increment the previous index
                previous++;
                // copy the current element to the previous index
                nums[previous] = nums[current];
                // increment the count
                count++;
            }
        }
        else {
            // increment the previous index
            previous++;
            // copy the current element to the previous index
            nums[previous] = nums[current];
            // reset the count
            count = 1;
        }
    }
    // return the new size of the array
    return previous + 1;
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int len = sizeof(nums) / sizeof(nums[0]);
    int size = removeDuplicates(nums, len);
    printf("%d\n", size);
}