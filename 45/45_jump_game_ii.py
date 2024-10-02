from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        maxJumps = 0
        maxReachable = 0
        current = 0
        jumps = 0
        for i in range(len(nums) - 1):
            if i + nums[i] > maxReachable:
                maxReachable = i + nums[i]
            if i == current:
                jumps += 1
                current = maxReachable
        return jumps

if __name__ == "__main__":
    print(Solution().jump([2,3,0,1,4]))