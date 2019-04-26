// 283 Move Zeroes
//
// 给定以个非负整数数组，将数组中的0都移动到数组的最后面，原本的顺序不变。
//

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // stable_partition(nums.begin(), nums.end(), [](int n){return n!=0;});
        int n = nums.size();
        int j = 0;
        for (auto i : nums) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < n; j++)
            nums[j] = 0;
};
