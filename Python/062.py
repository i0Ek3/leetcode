#!/usr/bin/env python3

class Solution(object):
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0 for i in range(n+1)] for j in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if i == 1 or j == 1:
                    f[i][j] = 1
                else:
                    f[i][j] = f[i-1][j] + f[i][j-1]
        return f[i][j]
