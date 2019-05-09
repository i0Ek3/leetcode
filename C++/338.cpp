// 338 Counting Bits
//
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
// 给定非负整数num。 对于0≤i≤num范围内的每个数字i，计算其二进制表示中的1的数量并将它们作为数组返回。
// 看了半天也没看懂题目想要表达什么意思，翻译了一下还是没看懂，可能是我太蠢了！作罢！
// 但是看了评论区的代码，感觉很简单啊？真是见鬼了！
//
//

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i-1)] + 1;
            // res[i] = i % 2 + res[i/2];
        }
        return ret;
    }
};
