// 236 Lowest Common Ancestor of a Binary Tree
//
// LCA，找出二叉树中给定两个节点的最低公共祖先。
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//
// 如果给定的两个节点是兄弟节点，那个LCA就是他们的父节点。如果两个节点在一条路径上，那么靠前的节点是LCA。如果不在一条路径上，那么LCA为高度较低的那个节点的父节点。如果给定的两个节点在不同子树上，那么他们的LCA则为根节点。
//
// 大抵上就是这样了，其他的再考虑特殊情况就行。看了大神的方案，感觉又想复杂了，树类的题目直接递归不好吗？


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
