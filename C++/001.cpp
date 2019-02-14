class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
                unordered_map<int, int> m;
                vector<int> result;
                for (int i = 0; i < nums.size(); i++) {
                        m[nums[i]] = i;
                }
                for (int i = 0; i < nums.size(); i++) {
                        int value = target - nums[i];
                        if (m.count(value) && m[value] != i) {
                                result.push_back(i);
                                result.push_back(m[value]);
                                break;
                        }
                }
                return result;
        }
};
