// 237 Delete Node in a Linked List
//
// 给定一个单向链表和一个节点，删除链表中给定的这个节点，返回删除后的链表。
//

class Solution {
public:
    void deleteNode(ListNode* node) {
        //*node = *node->next;
        auto next = node->next;
        *node = *next;
        delete next;
    }
};
