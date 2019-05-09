// 647 Palindromic Substrings
//
// 计算出给定字符串中有多少回文子串。不同下标对应的相同子串算不同的子串。
//
//

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        for (float center = 0.5; center < n; center += 0.5) {
            int left = int(center - 0.5);
            int right = int(center + 1);
            while (left >= 0 && right < s.size() && s[left--] == s[right++]) n++;
        }
        return n;
    }
};
