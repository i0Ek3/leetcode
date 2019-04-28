// 328 Odd Even Linked List
// 
// 链表操作，给定一个单链表，将链表中的数分为奇数和偶数，并记录这些节点的索引而不是其值。不知道在说啥？
//
// Example 1:
// Input: 1->2->3->4->5->NULL
// Output: 1->3->5->2->4->NULL
//
// Example 2:
// Input: 2->1->3->5->6->4->7->NULL
// Output: 2->3->6->7->1->5->4->NULL
//
//


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        ListNode* evenhead = head->next;
        ListNode* even = evenhead;
        while (even && even->next) {
            odd = odd->next->next;
            even = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }  
};
