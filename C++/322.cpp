// 322 Coin Challenge
//
// 似曾相识啊，是不是某个互联网的笔试题？腾讯？
//
// 如何用最少的硬币可以满足给定的钱数？最爱考的动态规划，你一定要会啊～
//
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
//

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i-c]+1);
            } 
        }
        return dp.back() > amount ? -1 : dp.back();
    }  
};
