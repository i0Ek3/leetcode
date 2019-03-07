// 072 Edit Distance
//
// 给定两个单词，word1 和 word2，转换 word1 到 word2，问最少要操作几次？还是同样的问题，动态规划，不过这个要难一丢丢。
//
// 规则给定，只允许你插入、删除和替换字符。
//
// 可参考这里：https://web.stanford.edu/class/cs124/lec/med.pdf

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

