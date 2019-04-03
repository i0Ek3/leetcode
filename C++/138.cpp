// 138 Copy List with Random Pointer
//
// 一个链表，除了 next 指针外，还包含一个可以指向任何节点的随机指针，返回一个链表的深拷贝。
//
// 怎么复制呢？大神们的方案是这样的：
//
//    1. 先复制原始链表并链接到原始链表之后
//    2. 用前继指针 p->random->next 来操作 random 指针
//    3. 分离原始链表和复制后的链表
//
// 真是优秀啊，我就是想不到。
//

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy(0);
        Node* p = head;
        Node* t = NULL;
        while (p) {
            Node *cloned = new Node(p->label);
            cloned->next = p->next;
            p->next = cloned;
            p = cloned->next;
        }

        p = head;
        while (p && p->next) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }

        p = head;
        t = &dummy;
        while (p && p->next) {
            t->next = p->next;
            p->next = p->next->next;
            t = t->next;
            p = p->next;
        }
        t->next = NULL;
        return dummy.next;
    }
};

