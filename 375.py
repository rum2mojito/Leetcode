// 375. Guess Number Higher or Lower II

class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n+1) for _ in range(n+1)]
        for gap in range(1, n):
            for lo in range(1, n+1-gap):
                hi = lo + gap
                dp[lo][hi] = min(x + max(dp[lo][x-1], dp[x+1][hi])
                                   for x in range(lo, hi))
        return dp[1][n]
