// 171 Excel Sheet Column Number
//
// 懒得翻译了，直接看原题吧。
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// Input: "AB"
// Output: 28
//
// Input: "ZY"
// Output: 701
//
// A -> 1
// Z -> 26
// AA -> 27
// AB -> 28
//

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }
        return ret;
    }
};
