// 538 Convert BST to Greater Tree
//
// 这题目描述的，fuck off！给定一棵BST，将该BST变为更大BST，即将每个节点上的值变成与比自己大的节点的值的和。
//
// 如 5 2 13 --> 18 20 13
//

class Solution {
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            root->val += sum;
            sum = root->val;
            convertBST(root->left);
        }
        return root;
    }
};
