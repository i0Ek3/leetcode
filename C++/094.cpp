// 094 Binary Tree Inorder Traversal
//
// 二叉树的中序遍历？如果仅仅是这样，那就简单多了。
//
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
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderTraversal(root, v);
        return v;
    }

    void inorderTraversal(TreeNode* root, vector<int> &v) {
        if (root == NULL) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }
};

class Solution2 {
public:
    vector<int> ret;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return vector<int>();
        if (root->left) inorderTraversal(root->left);
        ret.push_back(root->val);
        if (root->right) inorderTraversal(root->right);
        return ret;
    }
};
