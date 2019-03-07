// 070 Climbing Stairs
//
// 爬楼梯。你需要 n 步可以到达顶部，每次你可以爬 1 或者 2 步，问有多少种方法可以爬上顶部？递归也可以做，动态规划也可以做。
//
// 显然这样的写完不能满足编译器甚至面试官，我们需要改变些什么，以此来提升效率。

class Solution {
public:
    // 普通递归算法
    int climbStairs1(int n) {
        int path;
        if (n < 2) return n;
        else {
            path = climbStairs(n-1) + climbStairs(n-2);
        }
        return path;
    }

    // 面试的时候推荐下面的写法
    int climbStairs2(int n) {
        int a = 1, b = 1, tmp = 1;
        for (int i = 2; i < n+1; i++) {
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return tmp;
    }

    // dp 解法
    int climbStairs3(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

