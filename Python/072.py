class Solution:
    def minDistance(self, w1: str, w2: str) -> int:
        m, n = len(w1), len(w2)
        dp = [0] * (n+1)
        dp[0] = 0
        for j in range(1, n+1):
            dp[j] = j
        for i in range(1, m+1):
            res = dp[0]
            dp[0] = i
            for j in range(1, n+1):
                tmp, res = res, dp[j]
                if w1[i-1] == w2[j-1]:
                    dp[j] = tmp
                else:
                    dp[j] = min(dp[j], dp[j-1], tmp)+1
        return dp[n]
