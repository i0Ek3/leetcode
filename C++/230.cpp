// 230 Kth Smallest Element in a BST
//
// 找出BST中第K小的数。因为是bst树了，所以左小右大已经确定，可以中序遍历，记录每一个遍历到的值，遇到比其更小的则替换，找到指定数字即可。
//
// 哈，想法和大神们的一致，开心耶～
//

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }

    int find(TreeNode* root, int& k) {
        if (root) {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val : find(root->right, k);
        }
    }
};
