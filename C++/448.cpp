// 448 Find All Numbers Disappeared in an Array
//
// 找出数组中没有出现的数字，数组的长度为数字的范围。
//
//
//

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};
