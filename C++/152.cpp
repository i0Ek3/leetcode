// 152 Maximum Product Subarray
//
// 给定一个整数数组 nums，找出数组中连续的子数组使得该子数组的乘积最大，子数组中至少包含一个数。
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//
// 使用双指针
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = INT_MIN;
        int left = 0;
        int right = 0;
        for (int i = 0; i < n; i++) {
            left = left ? left * nums[i] : nums[i];
            right = right ? right * nums[n-1-i] : nums[n-1-i];
            product = max(product, max(left, right));
        }
        return product;
    }
};

// 看一下一位大神的答案。
//

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ret = nums[0];
        for (int i = 1, max = ret, min = ret; i < n; i++) {
            if (nums[i] < 0) swap(max, min);
            max = max(nums[i], max * nums[i]);
            min = min(nums[i], min * nums[i]);
            ret = max(ret, max);
        }
        return ret;
    }
};
