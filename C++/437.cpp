// 437 Path Sum III
// 
// 给定一棵二叉树，每个节点都包含一个整数，找出给定值的和的路径。
//
// 从根节点开始，从左至右，每经过一个节点便记录其值，大于给定值则切换到另一个节点上，
//
//
//

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return root ? dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }

    int dfs(TreeNode* root, int sum) {
        return root ? (root->val == sum) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val) : 0;
    }
};
