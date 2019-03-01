// 032 Longest Valid Parentheses
//
// 最长的有效括号。给定一个只包含 ‘(’ 和 ‘)’ 的字符串，找到有效且最长的括号子串。
//
// 如 ())   -> 2
//    ()()  -> 4
//    ()(() -> 4
//
// 对于括号类的应用我能想到的就是用栈。
//

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0;
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.size() > 1 && s[i] == ')' && s[st.top()] == '(') {
                st.pop();
                len = max(len, i - st.top());
            } else if (s[i] == '(') st.push(i);
            else st.top() = i;
        }
        return len;
    }
};
