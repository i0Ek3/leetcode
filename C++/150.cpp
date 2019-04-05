// 150 Evaluate Reverse Polish Notation
//
// 计算逆波兰表达式的值。
//
// 遇到一个符号，则将符号前面的两个运算数进行运算，需要将运算结果保存一下。
//
// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
// nput: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
//
// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation:
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//   = ((10 * (6 / (12 * -11))) + 17) + 5
//   = ((10 * (6 / -132)) + 17) + 5
//   = ((10 * 0) + 17) + 5
//   = (0 + 17) + 5
//   = 17 + 5
//   = 22
//

class Solution{
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> map = {
            {"+", [] (int a, int b) { return a + b; }},
            {"-", [] (int a, int b) { return a - b; }},
            {"*", [] (int a, int b) { return a * b; }},
            {"/", [] (int a, int b) { return a / b; }}
        };

        stack<int> st;
        for (string& s: tokens) {
            if (!map.count(s)) st.push(stoi(s));
            else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(map[s](op2, op1));
            }
        }
        return st.top();
    }
};
