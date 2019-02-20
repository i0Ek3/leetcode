class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (!st.empty()) return true;
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty(); // 空则完全匹配了，非空则不匹配
    }
};
