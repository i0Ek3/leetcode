// 141 Linked List Cycle
//
// 给定一个链表，判断它是否有环。pos 表示为环的入口节点的下标，输出为 -1 时则无环。
//
//
//

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
