// 010 Regular Expression Matching
//
// 原本的想法是，先直接判断两个字符串是否相等，相等则匹配；
// 接着判断p 带. 和 * 的情况。当然，我这想法简单，还没有全面考虑。也没有考虑到 @pezy 在解析中提到的最后这种类型的情况，即 aab 和 c*a*b 是否匹配。
// 再一个，.* 所表示的是 .. 或者 ... 或者是 ....
// 虽然这道题的难度是hard，但比起前面的一些题，我至少还能有些想法。

bool isMatch(const char* s, const char* p) {
    for (char c = *p; c != '\0'; ++s, c = *p) {
        if (p[1] != '*') ++p;
        else if (isMatch(s, p+2)) return true;
        if (!(c == *s || (c == '.' && *s != '\0'))) return false;
    }
    return *s == '\0';
}

bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    if ('*' == p[1]) { // 如果p的第二个字符是*
        // p.substr(2) 表示p的前两个字符
        return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
    } else {
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
}
