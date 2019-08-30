// 459 Repeated Substring Pattern
//
// 就是重复子串匹配。
//
// ababab 可以由三个 ab 组成。
//

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int j = 0;
        for (int i = 1; i < n/2; ++i) {
            if (n % i) continue;
            for (j = i; j < n && s[j%i] == s[j]; ++j) ;
            if (j == n) return true;
        }
        return false;
    }
};

// C 语言版的
bool repeatedSubstringPattern(char *s) {
    int n = strlen(s);
    char str[2*n - 1];
    memset(str, 0, sizeof(str));
    strncat(str, s+1, n-1);
    strncat(str, s, n-1);
    return strstr(str, s);
}
