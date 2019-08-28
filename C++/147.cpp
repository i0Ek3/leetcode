// 147 Insertion Sort List
//
// 类似于插入排序，从小到大。
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Soultion {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;

        auto prev = head, cur = head->next;
        while (cur != nullptr) {
            if (cur->val < prev->val) {
                prev->next = cur->next;
                ListNode *first = &dummy;
                ListNode *second = dummy->next;
                while (cur->val > second->val) {
                    first = first->next;
                    second = second->next;
                }
                first->next = cur;
                cur->next = second;
                cur = prev->next;
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};

class Solution { // 耗子叔的答案
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* sorted  = nullptr;
        while (head) {
            ListNode* phead = head;
            ListNode** pptail = &sorted;
            head = head->next;
            while (*pptail != nullptr && phead->val > (*pptail)->val) {
                pptail = &(*pptail)->next;
            }
            phead->next = *pptail;
            *pptail = phead;
        }
        return sorted;
    }
};
