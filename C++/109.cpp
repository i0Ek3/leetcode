// 109 Convert Sorted List to Binary Search Tree
//
/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        auto cur = head;
        int n = 0;
        while (cur) { // 计算链表结点个数
            cur = cur->next;
            ++n;
        }
        return helper(&head, 0, n); // 从链表头开始转换，一直到第n个
    }

    TreeNode* helper(ListNode **head, int begin, int end) {
        if (begin == end) return nullptr; // 如果链表为空，则不转换
        int mid = begin + ((end - begin)/2); // 采用二分法的特殊写法，这样精度更高
        auto left = helper(head, begin, mid); // 将中间节点左边的转换为二叉搜索树的左子树
        auto root = new TreeNode((*head)->val); // 确定跟节点

        *head = (*head)->next; // 将head指针指向root的下一个结点
        root->next = left;
        root->right = helper(head, mid+1, end); // 将中间结点右边的转换为BST的右子树
        return cur; // 返回BST
    }
};
