// 028 Implement strStr()
//
// 实现 strStr()，返回给定字符串在单词中首次出现的下标位置，没有则返回 -1.
//
//
class Solution {
    int strStr(string haystack, string needle) {
        if (needle.emtpy()) return 0;
        return haystack.find(needle);
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for ( ; j < m; j++) {
                if (i + j == n) return -1;
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == m) return i;
        }
        return -1;
    }
};
