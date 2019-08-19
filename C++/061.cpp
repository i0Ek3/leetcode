// 061 Rotate List
//
// Move list k position.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *fast = head;
        ListNode *slow = head;
        int len = 1;

        for (; fast->next && len <= k; ++len) {
            fast = fast->next;
        }

        if (k >= len) {
            k %= len;
            fast = head;
            for (int i = 0; i < k; ++i) {
                fast = fast->next;
            }
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next; 
        slow->next = nullptr;

        return head;
    }
};
