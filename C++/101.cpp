// 101 Symmetric Tree
//
// 给定一个二叉树，检查该二叉树是否是自己的镜像。这个算是基本题了，比较简单，正好早上在剑指 offer 上还看到了。
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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};
