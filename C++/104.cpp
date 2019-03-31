// 104 Maximum Depth of Binary Tree
//
// 就是输出二叉树的高度, 递归。
//


class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root == nullptr) return 0;
            return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
        }
};
