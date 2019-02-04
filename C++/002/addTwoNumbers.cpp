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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       // why dummy node? ref here: https://www.jianshu.com/p/3d4be8cbf94b
       // 这个问题本身非常简单，但想通过这个基本问题，引申出链表问题一个非常常见的技巧。即设立 dummy 节点，可以称为是傀儡节点，其作用在于让合成的新链表有一个着手点。这个节点的值可以随意，我们最终返回的，实际上是 dummy.next;
       ListNode dummy(0), *tail = &dummy;

       // typedef struct {
       //    int quot; // 商
       //    int rem; // 余数
       // } div_t;
       //
       for (div_t sum{0, 0}; sum.quot || l1 || l2; tail = tail->next) {
           // 本题的进位是基于十进制的，故两个节点相加之后的值，应判断是否超出了10，超出需要进位，留下的是余数。即，做了 div 操作后。sum.rem 是新链表的当前节点，sum.quot 是下一次加法运算的进位。
           if (l1) {
               sum.quot += l1->val;
               l1 = l1->next;
           }
           if (l2) {
               sum.quot += l2->val;
               l2 = l2->next;
           }
           sum = div(sum.quot, 10);
           tail->next = new ListNode(sum.rem);
       }
       return dummy.next;
    }
};
