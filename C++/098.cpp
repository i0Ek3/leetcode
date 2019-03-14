// 098 Validate Binary Search Tree
//
// BST，就是问你这棵树是不是二叉搜素树。
//
// 左小右大，左右子树又分别是 BST。还是基本题，哈哈哈。
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long low, long high) {
        if (!root) return true;
        return low < root->val && root->val < high && isValidBST(root->left, low, root->val) && isValidBST(root->right, root->val, high);
    }
};
