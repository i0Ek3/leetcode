// 062 Unique Paths
//
// 唯一路径。一个机器人在 m x n 的格子的左上角，标记为开始，右下角标记为完成。
//
// 机器人每次只能向下或者向上移动一格，该机器人试图走到最终的位置，即标记为完成的格子。请问有多少种可能？
//
// 这道题就是典型的动态规划了吧，多么似曾相识啊～
//
// 动态规划的核心就是 DP[i][j] = DP[i - 1][j] + DP[i][j - 1]。

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        if (m < 2) return m;
        vector<int> path(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[j] += path[j - 1];
            }
        }
        return path[n - 1];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[m-1][n-1];
    }
};
