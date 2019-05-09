// 617 Merge Two Binary Tree
//
// 这里所谓的合并实际上是指将两棵二叉树对应的节点值相加，从而组成新的二叉树。
//
// 这个是真的简单！
//


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        if (!t1 && !t2) return nullptr;
        if (t1 && t2) {
            TreeNode* t = new TreeNode(t1->val + t2->val);
            t->left = mergeTrees(t1->left, t2->left);
            t->right = mergeTrees(t1->right, t2->right);
            return t;
        } 
    }
};
