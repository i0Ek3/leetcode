// 191 Number of 1 Bits
//
// 写个函数，输入无符号整数，然后输出1的个数。
//
// Input: 00000000000000000000000000001011
// Output: 3
// Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
//
// ref: https://leetcode.com/problems/number-of-1-bits/discuss/55120/Short-code-of-C%2B%2B-O(m)-by-time-m-is-the-count-of-1's-and-another-several-method-of-O(1)-time
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return bitset<32>(n).count();
        int cnt = 0;
        while (n) {
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    }
};
