// 114 Flatten Binary Tree to Linked List
//
// 将二叉树转换为链表，即先根后左再右的展开。
//
// 首先想到的还是递归。
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode* tmp = root->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
            }
            root->left = nullptr;
            root = root->right;
        }
    }
};
