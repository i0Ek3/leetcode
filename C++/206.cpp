// 206 Reverse Linked List
//
// 反转单向链表。
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
//
// ref: https://leetcode.com/problems/reverse-linked-list/discuss/58130/C%2B%2B-Iterative-and-Recursive
//

class Solution {
    public:
        ListNode* reverseList1(ListNode* head) {
            ListNode* cur = nullptr;
            while (head) {
                ListNode* next = head->next;
                head->next = cur;
                cur = head;
                head = next;
            }
            return cur;
        }

        ListNode* reverseList2(ListNode* head) {
            if (!head || !(head->next)) return head;
            ListNode* node = reverseList2(head->next);
            head->next->next = head;
            head->next = NULL;
            return node;
        }
};

