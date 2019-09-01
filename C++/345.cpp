// 345 Reverse Vowels of a String
//
//
/*
Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
*/

class Solution {
public:
    bool isv(char c) {
         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (!isv(s[i]) && i < j) i++;
            while (!isv(s[j]) && i < j) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
