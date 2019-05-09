// 461 Hamming Distance
//
// 我理解的海明距离就是对于给定的数的二进制中，对应位有几个是不同的？maybe
//
// 也许可以通过位运算来解决该问题！
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dis = 0;
        int n = x ^ y;
        while (n) {
            ++dis;
            n &= n - 1;
        }
        return dis;
    }
};
