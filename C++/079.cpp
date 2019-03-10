// 079 Word Search
//
// 给定一个二维面板和一个单词，如果这个单词存在于格子中，请找到它。只能垂直或者水平相邻构造单词，而不能斜着来，并且不能往回走。
//
// 题目大抵上就是这样了，直观感觉要用回溯法，或者 DFS 来做，因为每个格子都有 2 种或者 3 中走法，将构成不同的单词。
//
//

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    static bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y, vector<vector<bool>> &visited) {
        if (index == word.size()) return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if (visited[x][y]) return false;
        if (board[x][y] != word[index]) return false;
        visited[x][y] = true;
        bool ret = dfs(board, word, index + 1, x - 1, y, visited) || dfs(board, word, index + 1, x + 1, y, visited) || dfs(board, word, index + 1, x, y - 1, visited) || dfs(board, word, index + 1, x, y + 1, visited);
        visited[x][y] = false;
        return ret;
    }
};
