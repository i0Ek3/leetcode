// 096 Unique Binary Search Trees
//
// 给定n个数字，问可以构成几种bst。
//
// bst的特点是各节点左小右大，也许可以用递归实现。或者使用动态规划，可以让每一个节点都作为root，依次尝试。
//

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 3; i < n; i++) {
            dp[i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
