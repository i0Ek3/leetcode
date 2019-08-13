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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        
        for (int i = 0; i < n; i++) { // fast first
            fast = fast->next;
        }
        
        while (fast->next) { // together
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *del = slow->next; // delete slow->next
        slow->next = slow->next->next;
        delete del;
        return dummy.next;
    }
};
