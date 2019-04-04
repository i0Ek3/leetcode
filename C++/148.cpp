// 148 Sort List
//
// 使用常数空间复杂度在 O(n) 时间复杂度内排序一个链表。
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
//
// 两个指针快速排序，一个在前一个在后，交换大的值到后面。
//
// 然后看了下大神们的答案，也用了快慢指针，但似乎还用了归并排序。下面的这个答案的时间复杂度为O(lgn)
//

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;

        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        if (left != nullptr) cur->next = left;
        else cur->next = right;
        return dummy.next;
    }
};
