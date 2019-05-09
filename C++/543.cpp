// 543 Diameter of Binary Tree
//
// 计算树的直径，树的直径为树中两个节点之间最远的距离，直径不一定经过root节点。
//
//

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        dfs(root, res);
        return res - 1;
    }

    vector<int> dfs(TreeNode* root, int& res) {
        if (root == nullptr) return {0, 0};
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        int path = max(left[0], left[1]) + max(right[0], right[1]) + 1;
        res = max(res, path);
        return {max(left[0], left[1]) + 1, max(right[0], right[1]) + 1};
    }
};
