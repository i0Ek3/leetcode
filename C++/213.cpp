// 213 打家劫舍 II
//
// 不能同时抢劫第一个和最后一个，所以，要么抢第一个，要么抢最后一个，或者都不抢。
//

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        dp1[1] = nums[0];
        dp2[1] = nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i-1]);
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp1[nums.size()-1], dp2[nums.size()-1]);
    }
};
