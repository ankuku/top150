#include <iostream>
using namespace std;

/**
* Remove all instances of a value from an array.
*
* @param nums The array to modify
* @param numsSize The size of the array
* @param val The value to remove
* @return The new size of the array after removing all instances of val
*/

class Solution {
public:
    int removeElement(int* nums, int numsSize, int val) {
        int i = 0;
        for (int j=0; j<numsSize; j++) {
            // If the current element is not the value to remove
            if (nums[j] != val) {
                // Copy it to the correct position
                nums[i] = nums[j];
                // Increment the position
                i++;
            }
        }
        // Return the new size of the array
        return i;
    }
};

int main() {
    Solution sol;
    int nums[] = {0, 1, 2, 2, 3, 3, 0, 4, 2};
    int val = 2;
    int len = sizeof(nums) / sizeof(nums[0]);
    int size = sol.removeElement(nums, len, val);
    cout << size << endl;
}