#include <stdio.h>


int jump(int* nums, int numsSize) {
    int maxReachable = 0;
    int maxJumps = 0;
    int current = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (i + nums[i] > maxReachable) {
            maxReachable = i + nums[i];
        }

        if (i == current) {
            maxJumps++;
            current = maxReachable;    
        }
    }
    return maxJumps;
}

int main() {
    int nums[] = {2,3,1,1,4};
    printf("%d", jump(nums, 5));
    return 0;
}