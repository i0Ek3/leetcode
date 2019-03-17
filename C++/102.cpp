// 102 Binary Tree Level Order Traversal
//
// 给定一个二叉树，返回层序遍历的结点值。看起来简单，实际上需要仔细考虑。要你给出层序数组，那如何判断哪些数是同一层呢？
//
// 我是没想到要用 queue 或者 deque，但真的很神奇。pezy 的代码非常简短，也很明了。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root) {
            deque<TreeNode*> dq{root};
            while (!dq.empty()) {
                vector<int> vi;
                for (decltype(dq.size()) i = 0, n = dq.size(); i != n; ++i) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    vi.push_back(node->val);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
                ret.push_back(vi);
            }
        }
        return ret;
    }
};
