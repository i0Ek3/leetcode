// 395 Longest Substring with At Least K Repeating Characters
// 
// 最长子串中至少重复k次的字符的总次数。
//
// Input:
// s = "aaabb", k = 3
//
// Output:
// 3
//
// The longest substring is "aaa", as 'a' is repeated 3 times.
//

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty() || k > s.size()) return 0;
        if (k == 0) return s.size();

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        int mid = 0;
        while (mid < s.size() && m[s[mid]] >= k) mid++;
        if (mid == s.size()) return s.size();
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < s.size() && m[s[mid]] < k) mid++;
        int right = longestSubstring(s.substr(mid), k);

        return max(left, right);
    }  
};
