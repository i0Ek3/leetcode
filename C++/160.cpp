// 160 Interaction of Two Linked Lists
//
// 在两个交错的单链表中寻找第一个共同的节点，有则返回该节点的值，无则返回 null。
//
//

class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if (a == nullptr || b == nullptr) return nullptr;
        while (a != nullptr && b != nullptr && a != b) {
            a = a->next;
            b = b->next;
            if (a == b)
                return a;
            if (a == nullptr)
                a = headB;
            if (b == nullptr)
                b = headA;
        }
        return a;
    }
};
