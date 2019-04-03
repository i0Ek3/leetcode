// 136 Single Number
//
// 给定一个非空整数数组，每个数字都出现两次，只有一个出现一次，请找到这个数。
//
// 是不是似曾相识？通过位运算符可以解决此问题，还有一个是有连个数不同，其他的都一样，仍然可以用位运算解决。
//
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i : nums)
            result ^= i;
        return result;
    }
};
