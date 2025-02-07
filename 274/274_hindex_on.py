from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        freq = [0] * (n + 1)

        # Build the frequency array
        for c in citations:
            if c >= n:
                freq[n] += 1
            else:
                freq[c] += 1

        # Accumulate citations and calculate the H-index
        total = 0
        for i in range(n, -1, -1):
            total += freq[i]
            if total >= i:
                return i
        return 0

if __name__ == '__main__':
    s = Solution()
    print(s.hIndex([3, 0, 6, 1, 5]))