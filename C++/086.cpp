// 086 Partition List
//
// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
/*
You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 定义两个dummy结点，遍历链表，将小于目标值的放在第一个dummy中，大于等于的放在第二个dummy中。然后将第二个dummy插入到第一个dummy后即可。

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);
        ListNode *prev1 = dummy1, *prev2 = dummy2;
        ListNode *cur = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                prev1->next = cur;
                cur = cur->next;
                prev1 = prev1->next;
                prev1->next = nullptr;
            } else {
                prev2->next = cur;
                cur = cur->next;
                prev2 = prev2->next;
                prev2->next = nullptr;
            }
        }
        prev1->next = dummy2->next;
        ListNode *node = dummy1->next;
        delete dummy1;
        delete dummy2;
        return node;
    }
};

