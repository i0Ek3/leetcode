// 198 House Robber
//
// 给出一个代表每个房子的金额的非负整数列表，确定今晚可以抢劫的最大金额而不引起警报。
//
// 就是说不能抢劫相邻的两个房子，问最大能抢多少钱。
//
//

class Solution {
public:
    int rob(vector<int>& nums)  {
        int n = nums.size();
        int pre = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i & 1) {
                x = max(x + nums[i], y);
            } else {
                y = max(y + nums[i], x);
            }
        }
        return max(x, y);
    }
};
