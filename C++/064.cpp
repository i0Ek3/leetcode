// 064 Minimum Path Sum
//
// 给定一个 m x n 的格子，被非负整数填充，找到一条路径从左上角到右下角，使得其路径上的数字之和最小，每次只可以向下或者向右移动。如果我没理解错，题意大概就是这些了。
//
//     [1,3,1]
// 如  [1,5,1] ，从左上到右下最小路径为 1->3->1->1->1->1，其他的均不满足，还是动态规划的问题。
//     [4,2,1]
//
//

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for (decltype(b) i = 0; i < n; i++) {
            int m = grid[0].size();
            for (decltype(m) j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid.back().back();
    }
};
