// 186 Reverse Words in a String II [Locked]
//
// 

/*
Given an input string , reverse the string word by word.

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note:

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

class Solution { // @kamyu104
public:
    string reverseW(string s, int k) {
        for (int l = 0; l < s.size(); l += 2 * k) {
            for (int i = l, j = min(l + k - 1), static_cast<int>(s.size())-1); i < j; ++i, --j) {
                std::swap(s[i], s[j]);
            }
        }
        return s;
    }
};

class Solution {
// 双指针策略，我们先反转字符串。然后用第一个指针指向第一个单词的开头，另一个指针遍历该单词。遇到空格则停止，移动第一个指针到下一个单词，继续如此。
public:
    void reverseW(vector<char> &s) {
        std::reverse(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size(); i = j + 1) {
            for (j = i; j < s.size(); ++j) {
                if (s[j] == ' ') break;
            }
            std::reverse(s.begin()+i, s.begin()+j);
        }
    }
};
