// 371 Sum of Two Integers
//
// 在不使用加法和减法的情况下计算两个数的和。
//
// 位运算可以很好的解决该问题，看看大神的回答吧！https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int c = a & b;
        while (c != 0) {
            c <<= 1;
            int sum_prim = sum ^ c;
            c = sum & c;
            sum = sum_prim;
        }
        return sum;
    }
};
