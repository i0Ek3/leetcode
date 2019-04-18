// 189 Rotate Array
//
// 给定一个数组，旋转给定步数，输出旋转后的数组。就是给定一个整数，从后往前旋转这个整数次，大概意思就是这样。
//
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?
//
// 那么最先想到的解法就是排序算法，要求O(1) 空间复杂度。虽然是简单的难度，但还是没啥其他思路，看看大神们的答案吧！
//

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k % n) {
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin() + k % n);
            reverse(nums.begin() + k % n, nums.end());
        }
    }
};
