from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        """
        Calculate the total amount of rainwater that can be trapped between the bars
        represented by the input height array. Each element in the array represents
        the height of a bar at that position.

        The algorithm uses two auxiliary arrays to store the maximum height of the
        bars to the left and right of each position. It then calculates the trapped 
        water at each position by finding the minimum of the maximum heights from the 
        left and right, and subtracting the height at that position.

        :param height: A list of non-negative integers representing the height of bars
        :type height: List[int]
        :return: The total amount of trapped rainwater
        :rtype: int
        """
        

        if not height or len(height) < 3:
            return 0
 
        n = len(height)
        left_max = [0] * n
        right_max = [0] * n

        reversed_height = height[::-1]

        trapped_water = [0] * n

        left_max[0] = height[0]
        right_max[0] = reversed_height[0]

        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], height[i])
            right_max[i] = max(right_max[i - 1], reversed_height[i])

        right_max = right_max[::-1]

        for i in range(n):
            trapped_water[i] = min(left_max[i], right_max[i]) - height[i]

        return sum(trapped_water)


if __name__ == "__main__":
    print(Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))