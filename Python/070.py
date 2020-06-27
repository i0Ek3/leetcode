class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 1, 2
        for _ in range(3, n):
            a, b = b, a+b
        return a+b if n > 2 else n
