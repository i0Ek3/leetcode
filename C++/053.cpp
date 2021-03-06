// 053 Maximum Subarray
//
// 最大子数组。给定一个整数数组 nums，找到一个至少包含一个数字的连续子数组，其数组中元素之和最大，并返回这个和。
//
// 我们来分析一下，题意大概就是想说，给一个数组，找出这么一个子数组，可以由一个数组成，但必须是连续的，只要它的和最大就行。
//
// 那么，对于 -2，1，-3，4，-1，2，1，-5，4 来说，以 -2 为首的子数组可以是如下这样的：-2 可以作为一个单独的子数组，-2，1 可以作为一个子数组，以此类推，这样的可以有 9 个子数组。
//
// 同理，以 1 开头和以其他元素开头的子数组分别有 8，7，6，5，4，3，2，1 个。那么，这些子数组里面哪个符合条件呢？那就分别计算下它们的和呗，我是这样想的。
//
// 放眼望去，几乎全是动态规划，还有些分治。
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for (auto i : nums) {
            if (sum > 0) sum += i;
            else sum = i;
            ans = std::max(ans, sum);
        }
        return ans;
    }
};
