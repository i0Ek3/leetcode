// 108 Convert Sorted Array to Binary Search Tree
//
// 给定一个按升序排列的数组，把它转换为 BST，即一棵二叉搜索树，数组中有负数。
//
// 相当于一个中序排序。

class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;
        auto mid = (left + right)/2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBST(nums, 0, n - 1);
    }

};
