// 082 Remove Duplicates from Sorted Lists II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0), *prev = &dummy;
        while (head) {
            if (head->next && head->next->val == head->val) {
                auto val = head->val;
                while (head && val == head->val) {
                    head = head->next;
                }
                prev->next = head;
            } else {
                prev->next = head;
                prev = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
