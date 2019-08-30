// 067 Add Binary
//
// 就是二进制树相加，考虑进位和字符串插入的问题即可。
//

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        while (n < m) { a = '0' + a; ++n; } // 短的在前面补0
        while (n > m) { b = '0' + b; ++m; }
        for (int i = n-1; i > 0; --i) {
            a[i] = a[i] - '0' + b[i];
            if (a[i] >= '2') { // >2则进1
                a[i] = (a[i] - '0') % 2 + '0';
                a[i-1] += 1;
            }
        }
        a[0] = a[0] - '0' + b[0]; // 第0位相加
        if (a[0] >= '2') {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};
