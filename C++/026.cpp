// 026 Remove Duplicates From Sorted Array
//
//


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) cnt++;
            else nums[i-cnt] = nums[i];
        }
        return n-cnt;
    }
};
