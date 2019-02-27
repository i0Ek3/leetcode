// 633 Sum of Square Numbers
//
// 类似两数之和的题型，都是双指针的应用。
//

class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0;
        long j = sqrt(c);
        while (i <= j) {
            long  sum = i * i + j * j;
            if (sum < c) i++;
            else if (sum > c) j--;
            else return true;
        }
        return false;
    }
};
