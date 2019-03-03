// 037 Sudoku Solver
//
// 解决数独谜题。规则和上一题类似，即：
//      1～9 的每个数字都要在每一行出现一次
//      1～9 的每个数字都要在每一列出现一次
//·     1～9 的咩哥数字都要在每个小的九宫格里出现一次
//      表格中的空白处由 . 表示
//      假设有且仅有唯一解
//      9 x 9 的格子
// 规则就是这样，说实话，没思路。但能想到最简单的做法便是一个一个试，显然不太合理。看了 pezy 的答案，DFS + 回溯，短小精悍哈！但说实在的，对这种题实在无感，所以 pezy 的答案对我来说仍然不是最好的，
//
//
//


class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 9; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j) && solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

private:
    bool isValid(const vector<vector<char>> &board, int x, int y) { // isValid(x. y)
        for (int i = 0; i < 9; i++) { // check col
            if (i != x && board[i][y] == board[x][y]) return false;
        }
        for (int j = 0; j < 9; j++) { // check row
            if (j !=  y && board[x][j] == board[x][y]) return false;
        }
        for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++) { // check box
            for (int j = 3 * (x / 3); j < 3 * (x / 3 + 1); j++) {
                if ((i != x || j != y) && board[i][j] == board[x][y]) return false;
            }
        }
        return true;
    }
};
