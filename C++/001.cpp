class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = res.find(target - nums[i]);
            if (it != res.end()) return {it->second, i};
        }
        res[nums[i]] = i;
    }
};
