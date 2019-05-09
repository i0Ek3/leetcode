// 560 Subarray Sum Equals K
//
// 找出数组中有几组和为k的连续数字。
//
//
//

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, sum = 0;
        map<int, int> res;
        resp[0]++;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            cnt += res[sum - k];
            res[sum]++;
        }
        return cnt;
    } 
};
