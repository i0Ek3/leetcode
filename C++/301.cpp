// 301 Remove Invalid Parentheses
//
// 移除多余的括号，使得剩下的字符串有效，即括号匹配。类似之前的某个题目，栈或者dfs应该都可以解决。
//
//

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0, pair = 0;
        unordered_set<string> res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(0, 0, left, right, s, "", res);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(int pair, int index, int left, int right, string s, string solution, unordered_set<string>& res) {
        if (index == s.size()) {
            if (pair == 0 && left == 0 && right == 0) res.insert(solution);
            return;
        }
        if (s[index] == '(') {
            if (left > 0) dfs(pair, index+1, left-1, right, s, solution, res);
            dfs(pair+1, index+1, left, right, s, solution+s[index], res);
        } else if (s[index] == ')') {
            if (right > 0) dfs(pair, index+1, left, right-1, s, solution, res);
            if (pair > 0) dfs(pair-1, index+1, left, right, s, solution+s[index], res);
        } else dfs(pair, index+1, left, right, s, solution+s[index], res);
    }
};
