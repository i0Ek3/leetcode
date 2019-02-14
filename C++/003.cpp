//
// Longest Substring Without Repeating Characters
//
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int MAX = 256;
        int last[MAX]; // 记录字符上次出现的位置
        int start = 0; // 子串起始位置

        memset(last, -1, sizeof(last)); // 初始化为-1
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= start) {
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
 };
