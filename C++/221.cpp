// 221 Maximal Square
//
// 给定一个由0和1构成的二维矩阵，返回矩阵中包含1的正方形的最大面积，类似于最大矩形那道题目。
//
// 所以可以考虑动态规划或者DFS。
//

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0; 
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i || !j || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
                else dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])) + 1;
                area = max(dp[i][j], area);
            }
        }
        return area * area;
    }
};
