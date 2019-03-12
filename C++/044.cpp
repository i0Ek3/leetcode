// 044 Wildcard Matching
//
// 就是正则表达式匹配，这里要求匹配 ？和 *，具体请看原题。
//

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        const char* begin = NULL;
        const char* end = s;
        while (*s) {
            if ((*p == '?') || (*p == *s)) { // ? 或者字母都可以匹配到，则匹配下一个
                s++;
                p++;
                continue;
            }
            if (*p == '*') { // 如果遇到 *，可能匹配多个字母，所以 p 向后移动
                begin = p++;
                end = s;
                continue;
            }
            if (begin) { //
                p = begin + 1;
                s = ++end;
                continue;
            }
            return false;
        }
        while (*p == '*') p++; // 遇 * 则后移
        return !*p;
    }
};
