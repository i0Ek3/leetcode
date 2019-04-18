// 190 Reverse Bits
//
// 旋转给定的32位无符号整数，就是完全倒置 bits。
//
// Input: 00000010100101000001111010011100
// Output: 00111001011110000010100101000000
// Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
//
// 大神用了我最喜欢的位运算，思想类似归并排序。就是先对半分开，每一半先进行倒置，然后将两边倒置的再分成两部分，重复重复。
//
// for 8 bit binary number abcdefgh, the process is as follow:
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
//

class Solution {
public:
    unit32_t reveseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xff00ff00) >> 4) | ((n & 0x00ff00ff) << 4);
        n = ((n & 0xff00ff00) >> 2) | ((n & 0x00ff00ff) << 2);
        n = ((n & 0xff00ff00) >> 1) | ((n & 0x00ff00ff) << 1);
        return n;
    }
};
