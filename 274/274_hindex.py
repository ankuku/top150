from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort()
        citationsSize = len(citations)
        for i in range(len(citations)):
            if citations[i] >= citationsSize - i:
                return citationsSize - i

if __name__ == '__main__':
    s = Solution()
    print(s.hIndex([3, 0, 6, 1, 5]))