// 300 Longest Increasing Subsequence
//
// 很常见的题型了吧？就是给定一个未排序数组，找出最长的递增子序列的长度。
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// wow it's so cool https://leetcode.com/problems/longest-increasing-subsequence/discuss/74989/C%2B%2B-Typical-DP-N2-solution-and-NLogN-solution-from-GeekForGeek

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(ret.begin(), ret.end(), nums[i]);
            if (it == ret.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return ret.size();
    }  
};
