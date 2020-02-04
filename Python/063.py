# https://leetcode-cn.com/problems/unique-paths-ii/solution/python3liu-xing-jian-ji-dai-ma-shi-jian-kong-jian-/

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid[0]), len(obstacleGrid)
        f = [1] + [0]*m
        for i in range(0, n):
            for j in range(0, m):
                f[j] = 0 if obstacleGrid[i][j] else f[j] + f[j-1]
        return f[-2]
