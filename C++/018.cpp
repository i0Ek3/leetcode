// 018 4Sum
//

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int target3 = target - nums[i];
            for (int j = i + 1; j < n; j++) {
                int target2 = target3 - nums[j];
                int front = j + 1;
                int tail = n - 1;
                while (front < tail) {
                    int sum = nums[front] + nums[tail];
                    if (sum < target2) front++;
                    else if (sum > target2) tail--;
                    else {
                        vector<int> quardruplet{nums[i], nums[j], nums[front], nums[tail]};
                        result.push_back(quardruplet);
                        while (front < tail && nums[front] == quardruplet[2]) ++front;
                        while (front < tail && nums[tail] == quardruplet[3]) --tail;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return result;
    }
};

