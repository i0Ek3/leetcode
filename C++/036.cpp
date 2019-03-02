// 036 Valid Sudoku
//
// 数独。似乎我没怎么玩过这个游戏，看看它的规则是啥。
//      每一行都必须包含数字 1～9，并且没有重复；
//      每一列都必须包含数字 1～9，并且没有重复
//      每一个 3x3 的小格子必须包含数字 1～9，并且没有重复
// 这就是规则了，总之就是要包含数字 1～9.
//
// 第一直觉以为这是数学类题目，需要有较好的思维反射。看了别人的答案后发现，其实倒不如说成是细节类型的题目，因为只需要我们挖掘那三条规则，就可以很好的解决这道题了。
//
// 所以，考虑一个二维数组，分别检查行、列和九宫格是否有重复即可。
//

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<size_t, unordered_set<char>> row, col, cell; // 这里定义了三个 map
        for (size_t i = 0; i < board.size(); i++) { // 遍历整理 board
            for (size_t j = 0; j < board[0].size(); j++) { // 遍历每一行
                // 将输入中给出的值插入到相应 map 中
                if (board[i][j] == '.') continue;
                if (!row[i].insert(board[i][j]).second) return false;
                if (!col[j].insert(board[i][j]).second) return false;
                if (!cell[i/j].insert(board[i][j]).second) return false;
            }
        }
        return true;
    }
};
