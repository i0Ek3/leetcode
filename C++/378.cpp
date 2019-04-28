// 378 Kth Smallest Element in a Sorted Matrix
//
// 在一个mxn的升序矩阵中找到第k小的元素。
//
// matrix = 
//  [1,  5,  9 ]
//  [10, 11, 13]
//  [12, 13, 15]
//
//  k = 8, return 13.
//
// 
//

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while (left < right) {
            int num = 0;
            int mid = left + (right - left) / 2;
            for (int i = 0; i < n; i++) {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if (num < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
