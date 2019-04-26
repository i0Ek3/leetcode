// 289 Game of Life
//
// 这种题目一点都看不进去，还怎么做题？对，不做了！
//
// 好吧，我又回来了，看了这位大佬的帖子，似乎明白了些什么。https://leetcode.com/problems/game-of-life/discuss/73223/Easiest-JAVA-solution-with-explanation
//
// /*
// 状态: 前一位表示下一代的状态,后一位表示当前的状态
// 00: 死->死
// 10: 死->活
// 01: 活->死
// 11: 活->活
// */
//
//

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (n == 0 || m == 0) return;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int lives = livesNeighbor(board, n, m, i, j);
                if (board[i][j] == 1 && lives >= 2 && lives <= 3)
                    board[i][j] = 3;
                if (board[i][j] == 0 && lives == 3)
                    board[i][j] = 2;
            }
        }  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }

    int livesNeighbor(vector<vector<int>>& board, int n, int m, int i, int j) {
        int lives = 0;
        for (int x = max(i - 1, 0); x <= min(i + 1, n - 1); x++) {
            for (int y = max(j - 1, 0); y <= min(j + 1, m - 1); y++) {
                lives += board[x][y] & 1;
            }
        }
        lives -= board[i][j] & 1;
        return lives;
    }
};
