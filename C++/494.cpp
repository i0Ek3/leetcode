// 494 Target Sum
//
// 给定一个数组和指定值，你可以用+或者-来重新定义你的数组中的值，使得数组中数字的和为指定值，问你有多少种方法。
//
// 这里有一份很优秀的答案，可以参考：https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation。
//


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum < S || (sum + S) & 1 ? 0 : subsetSum(nums, (sum + S) >> 1;
    }

    int subsetSum(vector<int>& nums, int S) {
        int dp[S+1] = {0};
        dp[0] = 1;
        for (int n : nums)
            for (int i = S; i >= n; i--)
                dp[i] += dp[i-n];
        return dp[S];
    }
};
