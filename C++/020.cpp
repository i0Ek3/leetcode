class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty()) return true;
            if ((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{')) st.pop();
            else st.push(c);
        }
        return st.empty(); // 空则完全匹配了，非空则不匹配
    }
};
