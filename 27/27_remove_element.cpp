#include <iostream>
#include <vector>
using namespace std;

/**
* Remove all instances of a value from an array.
*
* @param nums The array to modify
* @param val The value to remove
* @return The new size of the array after removing all instances of val
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j=0; j<nums.size(); j++) {
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
    vector<int> nums = {0, 1, 2, 2, 3, 3, 0, 4, 2};
    int val = 2;
    int size = sol.removeElement(nums, val);
    cout << size << endl;
}