from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        """
        There are n children standing in a line for the children's day treats. Each child has a rating for how good they were at the task. 
        You want to give them a candy each in such a way that each child gets a candy that is at least as good as the ones in front of them 
        that have a higher rating. What is the minimum number of candies you must give?

        :param ratings: The ratings of the children
        :type ratings: List[int]
        :return: The minimum number of candies
        :rtype: int
        """
        candies = [1] * len(ratings)

        for i in range(1, len(candies)):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1

        for i in range(len(candies) - 2, -1, -1):
            if (ratings[i] > ratings[i + 1]) and (candies[i] <= candies[i + 1]):
                candies[i] = candies[i + 1] + 1

        return sum(candies)

if __name__ == "__main__":
    s = Solution()
    print(s.candy([1,0,2]))