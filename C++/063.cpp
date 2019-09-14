// 063 不同路径和 2
//
// 之前那个没有障碍物，这个有障碍物。
//

class Solution {
public:
    int solution(vector<vector<int>> &gird) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        long long dp[n][m];
        dp[0][0] = grid[0][0] == 0 ? 1 : 0;
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = grid[i][0] == 1 ? 0 : dp[i-1][0];
        }
        
        for (int j = 1; j < m; ++j) {
            dp[0][j] = grid[j][0] == 1 ? 0 : dp[0][j-1];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] == 1 ? 0 : dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return dp[n-1][m-1];
    } 
};
