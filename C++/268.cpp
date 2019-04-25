// 268 Missing Number
//
// 找出数组中缺失的数字，这道题目似曾相识呢！数组中的数字是从0到n的，没有相同的数字。
//
// 先排序的话，时间复杂度可能会有点大。如果用哈希表记录的话，不知如何？其实最开始想的是位操作～
//

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (auto num : nums) {
            n ^= num;
            n ^= i;
            i++;
        }
        return n;
    }

    int missingNumber(vector<int>& nums) {
        int miss = 0;
        int i = 0;
        for (auto num : nums)
            miss += ++i - num;
        return miss;
    }
};
