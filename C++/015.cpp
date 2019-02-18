// 015 3Sum
//
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i]; // 0
            int front = i + 1;
            int tail = nums.size() - 1;
            while (front < tail) {
                int sum = nums[front] + nums[tail];
                if (sum < target) front++;
                else if (sum > target) tail--;
                else {
                    vector<int> triplet{nums[i], nums[front], nums[tail]};
                    result.push_back(triplet);
                    // 跳过重复的数字
                    while (front < tail && nums[front] == triplet[1]) front++;
                    while (front < tail && nums[tail] == triplet[2]) tail--;
                }
            }
            while (i != nums.size() && i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int front = i + 1;
            int tail = nums.size() - 1;
            while (front < tail) {
                int sum = nums[i] + nums[front] + nums[tail];
                if (sum < 0) front++;
                else if (sum > 0) tail--;
                else {
                    vector<int> triplet{nums[i], nums[front], nums[tail]};
                    result.push_back(triplet);
                    // 跳过重复的数字
                    while (front + 1 < tail && nums[front] == nums[front + 1]) front++;
                    while (front < tail - 1 && nums[tail] == nums[tail - 1]) tail--;
                    front++;
                    tail--;
                }
            }
        }
        return result;
    }
};
