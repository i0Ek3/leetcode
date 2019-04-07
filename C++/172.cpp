// 172 Factorial Trailing Zeroes
//
// 给定一个整数 n，返回该整数的阶乘结果中 0 的个数。
//
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
//
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
//
// 原本想着是用该数阶乘的结果去 %10，但想来这样不对，没什么意义。
//

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        for (long long i = 5; n / i > 0; i *= 5) {
            ret += (n / i);
        }
        return ret;
    }
};

// 4ms/8m 100%/100%
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};
