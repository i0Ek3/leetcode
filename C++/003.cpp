//
// Longest Substring Without Repeating Characters
//
// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
// 可以用滑动窗口解决该问题，在这个窗口中都是无重复的字符，一直向右移动，遇到重复的字符时停止。
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) { // 滑动窗口
        int window[256] = {0};
        int left = 0, right = -1;
        int sum = 0;
        while (left < s.size()) {
            if (right < s.size() - 1 && window[s[right+1]] == 0) {
                right++;
                window[s[right]]++;
            } else {
                window[s[left]]--;
                left++;
            }
            sum = max(sum, right - left + 1)
        }
        return sum;
    }
};


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
