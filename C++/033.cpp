// 033 Search in Rotated Sorted Array
//
// 对原本升序的数组进行旋转，但并不知道基准是哪一个。给定一个目标数，数组中如果存在则返回其索引，否则返回 -1。数组中可以没有相同的元素，注意时间复杂度的要求。
//
// 说实在的，我不知道这个旋转数组有什么关系。如果仅仅是找出给定数组的下标，那也过于简单了。又看了下题目，发现我们要找的目标数的下标是在已经旋转过的数组进行的，好吧，我还是不理解有啥关联，笑 cry 了。
//
// 但既然是关于查找的，那么那些查找算法便可以考虑了。这里我们用二分查找来解决这个我认为不怎么样的题。
//
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size();
        while (first != last) {
            const int m = first + (last - first) / 2;
            if (nums[m] == target) return m;
            if (nums[first] <= nums[m]) {
                if (nums[first] <= target && target < nums[m]) last = m;
                else first = m + 1;
            } else {
                if (nums[m] < target && target <= nums[last - 1]) first = m + 1;
                else last = m;
            }
        }
        return -1;
    }
};
