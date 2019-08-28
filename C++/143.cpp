//143 Reorder List
/*
 * 目前没啥想法，也看不懂啥意思。
 *
 * 看别人的答案，方法似乎是先找到链表的中间结点，然后翻转中间节点及其之后的链表，然后再将翻转后的链表和未翻转的链表依次拼接起来。
 *
 * 
 *
 *
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // 正常
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        deque<ListNode*> dq;
        ListNode *cur = head;
        while (cur != nullptr) {
            dq.push_back(cur);
            cur = cur->next;
        }

        int left = 0;
        int right = dq.size() - 1;
        while (left < right) {
            dq[left]->next = dq[right];
            dq[right--]->next = dq[++left];
        }
        dq[left]->left = nullptr;
    }
};


class Solution { // 超时
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = nullptr;
        while (slow) {
            ListNode *next = slow->next;
            slow->next = cur;
            cur = slow;
            slow = next;
        }
        ListNode *node = head;
        while (node) {
            ListNode *next = head->next;
            node->next = cur;
            node = cur;
            cur = next;
        }
    }
};
