// 387 First Unique Character in a String
// 
// 找出给定字符串中第一个不重复的字符的下标。
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
// 

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> m;
        for (auto& c : s) {
            m[c]++;
        }
        for (int i = 0; i < n; i++) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};
