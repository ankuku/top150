#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool canJump(int* nums, int numsSize) {
    int maxReachableIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReachableIndex) {
            return false;  // Stuck
        }
        if (i + nums[i] > maxReachableIndex) {
            maxReachableIndex = i + nums[i];
        }
    }
    return true;
}

int main() {
    int nums[] = {3,2,1,0,4};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", canJump(nums, size));
}