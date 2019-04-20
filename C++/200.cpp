// 200 Number of Islands
//
// 给定二维格子地图（首先想到DFS），1 代表陆地，0 代表水，计算出岛的数量。岛呢是被水围着的，形成的一块垂直或者水平的邻接陆地。
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = n ? grid[0].size() : 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
