// 214 Shortest Palindrome
//
// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
/*
Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"
*/

class Solution {
    string sp(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s[j]) ++i;
        }
        if (i == n) return s;
        string t = s.substr(i, n);
        reverse(t.begin(), t.end());
        return t + sp(s.substr(0, i)) + s.substr(i);
    } 
};

