// Pascal's Triangle
//
// 给定一列非负整数，输出一个帕斯卡三角形。该三角形的左右两条边都是 1，前两层也是 1，其他位置上的值便是上一层的两个数之和。
//
// 啊，就是杨辉三角！

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> row;
        for (int i = 0; i < numRows; i++) {
            row.push_back(1);
            for (int j = i - 1; j > 0; j--) {
                row[j] = row[j - 1] + row[j]
            }
            result.push_back(row);
        }
        return result;
    }
};
