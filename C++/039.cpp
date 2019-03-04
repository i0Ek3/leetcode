// 039 Combination Sum
//
// 给定一个没有重复数字的候选集合，和一个目标数 a，找出所有唯一的组合，使得候选数字之和等于目标数，这个组合中的数字可以重复。
//
// 如 candidates = [2, 3, 6, 7], target = 7, 则 set 为 [7], [2, 2, 3]。
//
// 我能想到的通用解法就是双指针，但似乎不太对。另一方面，这里要考虑结果里可以有重复的数字，所以先看候选数组里的每个数字是否可以被 target 整除，然后考虑它们中的某个或多个可以被整除，最后考虑和是否等于 target。总之，画个图写写才能更好的分析问题。
//
// 哈哈，成功把自己绕进去了。看了下大佬们的答案，不是回溯就是动态规划，可见我是真的太 low 了。不过看了下，还是 pezy 的答案最好理解。基于回溯，采用深度优先遍历来实现的。
//

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, vector<int>{}, 0, result);
        return result;
    }

    void dfs(const vector<int> &candidates, int target, vector<int> save, size_t index, vector<vector<int>> &result) {
        if (!target) {
            result.push_back(save);
            return ;
        }
        int n = candidates.size();
        for (auto i = index; i < n; ++i) {
            if (candidates[i] <= target) {
                save.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], save, i, result);
                save.pop_back();
            } else break;
        }
    }
};
