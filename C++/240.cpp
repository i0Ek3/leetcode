// 240 Search a 2D Matrix II
// 
// 在mxn的矩阵里找到某个值，矩阵从上到下，从左到右都是递增的。给定一个整数，输出true或者false，以表示是否在矩阵中。
//
// 如果从第一行开始，1 < 5，则去除第一行第一列后，5就是我们要找的值了。但答案似乎使用分治法，也没差。
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        int left = 0;
        int right = m - 1;
        while (left < n && right >= 0) {
            if (matrix[left][right] == target) return true;
        }
        matrix[left][right] > target ? right-- : left++;
    }
    return false;
};
