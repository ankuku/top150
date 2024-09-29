from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        Given an integer array nums sorted in non-decreasing order, 
        remove some duplicates in-place such that each unique element 
        appears at most twice. The relative order of the elements should 
        be kept the same.
        
        :param nums: The array to modify
        :type nums: List[int]
        :return: The new size of the array with duplicates removed
        :rtype: int
        """
        count = 1
        previous = 0
        for current in range(1, len(nums)):
            if nums[current] == nums[previous]:
                if count < 2:
                    previous += 1
                    nums[previous] = nums[current]
                    count += 1
            else:
                previous += 1
                nums[previous] = nums[current]
                count = 1
        return previous+1


if __name__ == "__main__":
    sol = Solution()
    nums = [1, 1, 1, 2, 2, 3]
    print(sol.removeDuplicates(nums))   