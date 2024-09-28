#include <iostream>
#include <vector> 
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int previous = 0;
        for (int current=1; current<nums.size(); current++) {
            if (nums[current] == nums[previous]) {
                if (count < 2) {
                    previous++;
                    nums[previous] = nums[current];
                    count++;
                }
            }
            else {
                previous++;
                nums[previous] = nums[current];
                count = 1;
            }
        }
        return previous+1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int size = sol.removeDuplicates(nums);
    cout << size << endl;
}