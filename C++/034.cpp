// 034 Find First and Last Position of Element in Sorted Array
//
// 给定一个按升序排好序的整数数组，找到给定目标数的起始和结束的位置。注意时间复杂度，如果没有找到，则返回 [-1, -1]。
//
// 跟上一题如出一辙，不过这里的数组可能会有重复的元素，所以要你返回起始和结束的位置，也就是下标。
//
//
//

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> res(2, -1);

        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (nums[left] != target) return res;
        else res[0] = left;

        right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        res[1] = right;
        return res;
    }
};
