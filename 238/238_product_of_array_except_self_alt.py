from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        len_of_nums = len(nums)
        output = [1] * len_of_nums

        left_product = 1
        for i in range(len_of_nums):
            output[i] = left_product
            left_product *= nums[i]

        right_product = 1
        for i in range(len_of_nums - 1, -1, -1):
            output[i] *= right_product
            right_product *= nums[i]

        return output

if __name__ == "__main__":
    nums = [1, 2, 3, 4]
    print(Solution().productExceptSelf(nums))