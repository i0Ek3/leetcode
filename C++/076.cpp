// 076 Minimum Window Substring
//
// 给定一个字符串 S 和字符串 T，用 O(n) 的复杂度在 S 中找到一个最小的窗口，使得其包含所有 T 中的字符。
//
// 如 S = "ADOBECODEBANC"，T = "ABC"，则输出 "BANC"。我理解的就是在 S 中找到某个最小区间的字符串可以包含 T 中的所有字母。
//
// 没啥思路，字符串的题向来不感冒。看了 soulmachine 的答案，使用双指针来动态维护一个区间，最终这个区间就是我们要求的。尾指针不断向后移，找到包含 T 所有字符的字符串后，头指针开始移动，直到该字符串不能再小了为止。
//
// 下面的解法是评论区 zefengsong 大神的答案，更加简洁，作为参考。

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> um;

        int i = 0, j = 0, count = 0;
        int min_len = INT_MAX;
        string ret = "";
        for (auto x : t) um[x]++, count++;
        while (j < n) {
            if (um[s[j++]]-- > 0) count--;
            if (count == 0) {
                while (um[s[i]] < 0) um[s[i++]]++;
                int len = j - i;
                if (len < min_len) {
                    min_len = len;
                    ret = s.substr(i, len);
                }
                um[s[i++]]++;
                count++;
            }
        }
        return ret;
    }
};

