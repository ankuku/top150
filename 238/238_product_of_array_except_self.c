# include <stdio.h>
# include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* output = (int*) malloc(sizeof(int) * numsSize);

    *returnSize = numsSize;

    int left_product = 1;

    for (int i=0; i<numsSize; i++) {
        output[i] = left_product;
        left_product *= nums[i];
    }

    int right_product = 1;
    for (int i=numsSize-1; i>=0; i--) {
        output[i] *= right_product;
        right_product *= nums[i];
    }

    return output;
}

int main() {
    int nums[] = {1,2,3,4};
    int len = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* output = productExceptSelf(nums, len, &returnSize);

    for (int i=0; i<len; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    free(output);
    return 0;
}