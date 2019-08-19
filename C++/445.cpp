// 445 Add Two Numbers II
//
// 可以先反转链表，然后再相加。但是这里采用大神们 stack 的作法。
//
// 因为加法是要从后往前计算的，而链表只能从前往后遍历，所以栈可以很好过渡这个问题。
//
// 用两个栈保存链表中的值，则栈顶元素就是我们要运算的第一个数，直到栈空为止。
//
// 需要考虑的一个问题是进位问题，若两个数的和大于 10，我们需要给前一位加上1，本位变为 0，
// 

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
        stack<int> st1, st2;
        while (l1) {
            st1.emplace(l1->val); // emplace() 用来直接构造元素
            l1 = l1->next;
        }
        while (l2) {
            st2.emplace(l2->val);
            l2 = l2->next;
        }
        
        ListNode *prev = nullptr, *head = nullptr;
        int sum = 0;
        while (!st1.empty() || !st2.empty()) {
            sum /= 10;
            if (!st1.emtpy()) {
                sum += st1.top();
                st1.pop()
            }
            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            head = new ListNode(sum % 10);
            head->next = prev;
            prev = head;
        }

        if (sum >= 10) {
            head = new ListNode(sum / 10);
            head->next = prev;
        }
        return head;
    }
};
