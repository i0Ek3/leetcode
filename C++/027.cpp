// 027 Remove Element
//
// 移除数组中重复的元素后，数组的长度。即给定要移除的数字，输出结果。
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        for (auto &num : nums)
            if (num != val) nums[left++] = num;
        return left;
    }
};
