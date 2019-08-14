// 144 Binary Tree Preorder Traversal
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
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        ret.push_back(root->val);
        if (root->left) {
            preorderTraversal(root->left);
        }
        if (root->right) {
            preorderTraversal(root->right);
        }
    }
};
