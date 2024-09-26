#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    // Merge in reverse order 
    while (i>=0 && j>=0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        }
        else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

// Visualize by printing the array
void printArray(int* nums, int size) {
    printf("[");
    for (int i=0; i<size; i++) {
        printf("%d", nums[i]);
        if (i<size-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int nums1[6] = {1, 3, 5, 0, 7, 6};  
    int m = 3;                             // Only the first 3 elements are valid
    int nums2[3] = {2, 4, 7}; 
    int n = 3;

    printf("Before merging:\n");
    printf("nums1: ");
    printArray(nums1, m+n);
    printf("nums2: ");
    printArray(nums2, n);

    merge(nums1, 0, m, nums2, 0, n);

    printf("\nAfter merging:\n");
    printf("nums1: ");
    printArray(nums1, m+n);

    return 0;
}