//
// 05 Longest Palindromic Substring
//
// @Monsooooon: From the code we can infer that the variable i only stop at the beginning of duplicate characters. For example, if the string is ACBBBCAAD, then the values for i will be 0(A) 1(C) 2(B) 5(C) 6(A) 8(D) As its result, in every loop, j and k sit at the begin and end of substring composed of duplicate characters, such as j == 2 and k == 4 for substring BBB, and then expand. In comparison, if variable i increases 1 in each loop, it will stop at position 2 or 4 and expand to left and right, but in such cases it will definitely fail since the left end and right end of BBB are not 'B'
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int begin = end = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l1 = helper(s, i, i); // 奇数拓展
            int l2 = helper(s, i, i+1); // 偶数拓展
            int len = max(l1, l2);
            if (len > end - begin) {
                begin = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(begin, end+1);
    }

    int helper(string s, int left, int right) { // 拓展中心
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R-L-1;
    }
};


string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        int max_len = 1;
        int begin = 0;
        for (int i = 0; i < s.size(); ) {
            if (s.size() - i <= max_len / 2) {
                break;
            }
            int j = i, k = i;
            while (k < s.size() - 1 && s[k + 1] == s[k]) {
                ++k;
            }
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                ++k;
                --j;
            }
            int new_len = k - j + 1;
            if (new_len > max_len) {
                begin = j;
                max_len = new_len;
            }
        }
        return s.substr(begin, max_len);
}


int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl;
}
