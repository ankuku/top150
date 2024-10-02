from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReachableIndex = 0
        for i in range(len(nums)):
            if i > maxReachableIndex:
                return False
            if i + nums[i] > maxReachableIndex:
                maxReachableIndex = i + nums[i]
        return True


if __name__ == "__main__":
    print(Solution().canJump([2,3,1,1,4]))