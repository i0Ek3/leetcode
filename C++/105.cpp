// 105 Construct Binary Tree from Preorder and Inorder Traversal
//
// 给定一个树的前序和中序遍历，构造一个二叉树。虽然我知道怎么构建，但你要让计算机可以识别出你的想法。
//
// 前序的第一个值就是根节点的值，然后中序序列中该根节点左边的是二叉树的左子树，根节点右边的是二叉树的右子树。
//

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if (pre.empty() || pre.empty()) return nullptr;
        TreeNode *root = new TreeNode(pre[0]);
        int i = find(in.begin(), in.end(), pre[0]) - in.begin();
        root->left = buildTree(vector<int>(pre.begin()+1, pre.begin()+i+1), vector<int>(in.begin(), in.begin()+i));
        root->right = buildTree(vector<int>)(pre.begin()+i+1, pre.end()), vector<int>(in.begin()+i+1, in.end()));
        return root;
    }
};

