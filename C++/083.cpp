// 83 Remove Duplicates from Sorted List
//
// EASY
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *node = head;
        while (node) {
            ListNode *next = node->next;
            while (next && next->val == node->val) {
                next = next->next;
            }
            node->next = next;
            node = next;
        }
        return head;
    }
};
