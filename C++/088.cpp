// 088 Merge Sorted Array
//
// 给定两个已经排好序的整数数组，合并两个数组。如 1，2，3，0，0，0 和 2，5，6 合并为 1，2，2，3，5，6.
//

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
            //if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            //else nums1[k--] = nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--]; // nums1 为空，直接将 nums2 中的数放过去即可
    }
};
