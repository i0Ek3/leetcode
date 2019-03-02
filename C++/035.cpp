// 035 Search Insert Position
//
// 给定一个排好序的数组和一个目标值，如果目标值在数组中可以找到，则返回其下标，否则返回这个目标值被按顺序后插入到数组中的下标。
//
// 如果没理解错，题意就是这样了。说实话，第一次没管三七二十一，我直接用最简单的办法来写的，对，就是想的那样：`if (nums[i] == target) return i;`，哈哈，果然是低级。
//
// 看了别人的答案，才发现应该用二分查找，这个好说，前面几道题不都这样嘛，再说了，二分查找也是我们必须掌握的呀，这个我会！所以说，下次看到有关查找类的题目，获取可以先考虑以下二分查找或者其他的查找算法。
//
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int high = n - 1;
        int low = 0;

        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
