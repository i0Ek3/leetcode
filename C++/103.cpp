// 103 Binary Tree Zigzag Level Order Traversal
//
// 层序遍历，不过输出的结果要求你按照 Z 字形的顺序来，就是一正一反这样的。是不是似曾相识？一个之前的 Z 醒齿，一个层序遍历打印，结合在一起是不是就 ok 了呢？
//
// 实则不然，既然要求按 Z 的形式来打印，自然有它的规律，我们可以看到奇数行是从左往右打印的，偶数行是从右往左打印的。这样是不是可以联想到栈了呢？那种先进后出，后进先出的特性？
//
// 对的，就是这样，我们需要两个栈来保存结点的值，还需要两个变量来记录当前打印情况，为什么不是一个呢？聪明的你一定可以想的出来！
//
// 不过这是剑指 offer 上的答案，我们来看看其他的。比如说队列，那么 queue 和 deque 都是可以的。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;

        while (!q.empty()) {
            vector<int> vi;
            int n = q.size();
            while (n--) {
                root = q.front();
                q.pop();
                vi.push_back(root->val);
                if (root->left != NULL) q.push(root->left);
                if (root->right != NULL) q.push(root->right);
            }
            if (i++ % 2 == i) reverse(vi.begin(), vi.end());
            ret.push_back(vi);
        }
        return ret;
    }
};

class Solution { // 剑指 offer 版
public:
    void zigzagLevelOrder(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st[2];
        int cur = 0, next = 1;
        st[cur].push(root);

        while (!st[0].empty() || !st[1].empty()) {
            TreeNode* pNode = st[cur].top();
            st[cur].pop();
            cout << pNode->val;
            if (cur == 0) {
                if (pNode->left) st[next].push(pNode->left);
                if (pNode->right) st[next].push(pNode->right);
            } else {
                if (pNode->right) st[next].push(pNode->right);
                if (pNode->left) st[next].push(pNode->left);
            }

            if (st[cur].empty()) {
                cout << endl;
                cur = 1 - cur;
                next = 1 - next;
            }
        }
    }
};
