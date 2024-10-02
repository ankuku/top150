#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJumps = 0;
        int maxReachable = 0;
        int current = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
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
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution sol;
    cout << sol.jump(nums) << endl;
    return 0;
}