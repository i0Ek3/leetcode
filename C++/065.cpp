// 65 有效数字
//
// 这道题忘了是哪个公司的笔试题目了。
//
/*
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
*/

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0, digit = 0, dot = 0;
        for (; i < n && isspace(s[i]); ++i);
        if (s[i] == '+' || s[i] == '-') i++;
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); ++i)
            isdigit(s[i]) ? digit++ : dot++;
        if (!digit || dot > 1) return false;
        if (s[i] == 'e') {
            i++;
            if (s[i] == '+' || s[i] == '-') i++;
            digit = 0;
            for (; i < n && isdigit(s[i]); ++i) digit++;
            if (!digit) return false;
        }
        for (; i < n && isspace(s[i]); ++i);
        return i == n;
    }
};
