// 025 Reverse Nodes in k-Group
//
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        ListNode dummy(-1);
        dummy->next = head;
        ListNode *curr = dummy, *next, *prev = dummy;
        int num = 0;
        while (curr = curr->next) num++; // num is the length of list
        while (num >= k) {
            curr = prev->next;
            next = curr->next;
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            num -= k;
        }
        return dummy.next;
    }
};
