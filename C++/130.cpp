// 130 Surrounded Regions
//
// 给定一个二维面板，包含字符 X 和 O，填充所有被 X 包围的区域，类似围棋的玩法。
//
// Example:
//
// X X X X
// X O O X
// X X O X
// X O X X
//
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X
//
// 记得之前看剑指 offer，说只要是和面板或者二维数组有关的算法题，用 DFS 或者回溯法准没错。
//
//

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            check(board, i, 0);
            check(board, i, col-1);
        }
        for (int j = 1; j < col-1; j++) {
            check(board, 0, j);
            check(board, row-1, j);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }

    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i-1, j);
            if (j > 1) check(board, i, j-1);
            if (i+1 < board.size()) check(board, i+1, j);
            if (j+1 < board[0].size()) check(board, i, j+1);
        }
    }
};


