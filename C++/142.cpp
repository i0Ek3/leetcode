// 142 Linked List Cycle II
//
// 返回链表中环的起始位置，如果没有环则返回null。
//


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pos = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (slow != pos) {
                    slow = slow->next;
                    pos = pos->next;
                }
                return pos;
            }
        }
        return nullptr;
    }
};
