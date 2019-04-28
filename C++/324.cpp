// 324 Wiggle Sort II
// 
// 给定一个未排序数组，使得nums[0] < nums[1] > nums[2] < nums[3]....
//
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
//
// 自己的一个想法是双指针，一个在前一个在后，如果slow < fast，继续比较下一个，如果slow > fast，继续比较下一个，以此类推。
//
// 看看大神是怎么解决的？先对数组进行排序，然后将数组分成两部分，前一部分都小于后一部分。然后将后一部分对应的插入前一部分的每个数字后面。
//
// https://leetcode.com/problems/wiggle-sort-ii/discuss/77706/Short-simple-C%2B%2B
//

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        int n = nums.size();
        for (int i = n - 1, j = 0, k = i / 2 + 1; i >= 0; i--) {
            nums[i] = sorted[i & 1 ? k++ : j++];
        }
    }
};
