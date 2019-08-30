// 242 Valid Anagram
//
// 有效相同字母异序词。即判断两个字符串是否是相同字母组成的不同顺序的词语。
//
// Input: s = "anagram", t = "nagaram"
// Output: true
// 
// 对字符串里的字母进行排序然后比较就行。要不统计下两个字符串中的字母个数？然后再比较一下。
//
// https://leetcode.com/problems/valid-anagram/discuss/66519/2-C%2B%2B-Solutions-with-Explanations
//

// 刚才无耻的用自带函数解决了这个问题，哈哈
// 就是效率不咋滴！
//
// 40ms + 9.5MB
//

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.begin());
        if (s == t) return true;
        else return false;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) return false;
        int count[26] = {0};
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i]) return false;
        }
        return true;
    }
};
