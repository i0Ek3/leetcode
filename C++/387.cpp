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

class Solution { // 这个效率要好于上面那个
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            v[s[i]-'a']++;
        }
        for (int i = 0; i < n; ++i) {
            if (v[s[i]-'a'] == 1) return i
        }
        return -1;
};
