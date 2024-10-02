#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReachableIndex) {
                return false;  // Stuck
            }
            if (i + nums[i] > maxReachableIndex) {
                maxReachableIndex = i + nums[i];
            }
        }
        return true;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 0, 4};
    Solution sol;
    cout << sol.canJump(nums) << endl;
}