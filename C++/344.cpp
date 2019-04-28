// 344 Reverse String
//
// 反转字符串，字符串是以char数组形式给定的。
//
// Input: ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// 
//
// Input: ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
//

class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
