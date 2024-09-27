from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        for j in range(1, len(nums)):
            if nums[j] != nums[j-1]:
                nums[i] = nums[j]
                i+=1
        return i



if __name__ == "__main__":
    sol = Solution()
    nums = [0, 0, 1, 1, 1, 1, 2, 3, 4, 4]
    print(sol.removeDuplicates(nums))