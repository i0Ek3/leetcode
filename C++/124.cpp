// 124 Binary Tree Maximum Path Sum
//
// 给定一个非空二叉树，找到最大路径之和。
//
// 窃以为这个 hard 级别的难度还是不够，不过回过神来，似乎也没那么简单。就像示例 2 所示，如果 -10 在右子树的根节点，那么最大路径之和便是 29.
//
// 大神们都是用 dfs 来做的。另外，lc 上每次提交的结果还不一样，运行时间也不同，多提交几次，就能找到最好的结果。
//

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        dfs(root, maxPathSum);
        return maxPathSum;
    }

    int dfs(TreeNode* root, int &maxPathSum) {
        if (!root) return 0;
        int left = max(0, dfs(root->left, maxPathSum));
        int right = max(0, dfs(root->right, maxPathSum));
        maxPathSum = max(maxPathSum, left + right + root->val);
        return max(left, right) + root->val;
    }
};
