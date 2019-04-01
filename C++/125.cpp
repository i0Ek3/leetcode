// 125 Valid Palindrome
//
// 给定一个字符串，判断它是不是一个回文串，忽略大小写，通过双指针解决。
//

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
