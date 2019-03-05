// 046 Permutations
//
// 前面做过类似的题，反正就是排列，输出所有组合的情况。
//
// 最简单的方法莫过于暴力猜解了，但显然这不是我们想要的结果。那还可以用什么来解决呢？哈哈，没有思路。大神们的方案都是用回溯思想，不过这里有个递归的例子。
//
// 怎么感觉题越来越难了呢？

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return {nums};
        vector<vector<int>> vec;
        vector<int> num;
        for (int i = 0; i < n; i++) {
            num = nums;
            num.erase(num.begin() + i);
            vector<vector<int>> v = permute(num);
            for (int j = 0; j < v.size(); j++) {
                v[j].insert(v[j].begin(), nums[i]);
                vec.push_back(v[j]);
            }
        }
        return vec;
    }
};
