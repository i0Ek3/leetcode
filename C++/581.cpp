// 581 Shortest Unsorted Continuous Subarray
//
// 最短未排序的连续子数组。在给定数组中找出最短的未经过排序的连续子数组，输出该子数组的长度。
//
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103062/C%2B%2B-Clean-Code-2-Solution-Sort-O(NlgN)-and-max-min-vectors-O(N)
//
// 自己写了一个最为朴素的解法，结果内存超出限制，所以需要考虑更好的办法。
//


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res(nums);
        sort(res.begin(), res.end());
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < n && nums[low] == res[low]) low++;
        while (high > low && nums[high] == res[high]) high--;
        return j - i + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i = 0, j = 1;
        vector<int> res;
        while (nums.begin() < nums.end()) {
            if (nums[i] <= nums[j]) {
                i++;
                j++;
            } else {
                res.push_back(i);
            }
        }
        return res.size();
    }
};
