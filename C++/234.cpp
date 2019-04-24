// 234 Palindrome Linked List
//
// 给定一个单向链表，判断是否是回文链表。
//
// Input: 1->2->2->1
// Output: true
// 
// Input: 1->2
// Output: false
//
// 初步想法是设定两个指针，一个在开始，一个在末尾。同时出发，所走过的数都相同的话，那就是回文链表了，反之不是。这个想法还是有点简单了，别人都用了链表反转，甚至确定中位数吗，只不过我觉着完全没有必要。
//
// 真的很奇怪，一模一样的代码，别人的就能提交，我的就是各种问题。 真的是一模一样呐～
//

class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (p == nullptr) return true;
        bool isPalindrome = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPalindrome;
    }
};

