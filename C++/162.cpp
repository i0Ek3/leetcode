// 162 Find Peak Element
//
// 峰值是指它比相邻的元素都大的值。给定一个输入数组 nums，且 nums[i] != nums[i+1]，找到该数组中的峰值并返回它的下标。
//
// 数组中可能有多个峰值，返回任意一个的下标就行。
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
//
// 最简单的想法应该就是直接判断了，满足条件则返回下标。
//

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                return i-1;
            }
        }
        return n-1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid1 = low + (high-low)/2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2]) low = mid2;
            else high = mid1;
        }
        return low;
    }
};
