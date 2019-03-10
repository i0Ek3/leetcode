// 078 Subsets
//
// 找出给定集合的子集，不允许包含重复子集。
//
// 感觉这样的题应该用递归来做。我们来分析一下，先找到空集，然后分别找出以集合中的元素为首的子集即可。如果仅仅用循环的话，就没有意义了。不知道我想的对不对。
//
// 嗯，我想的是对的，只不过代码还需要加强。
//

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> ret(1, vector<int>());
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int m = ret.size();
            for (int j = 0; j < m; j++) {
                ret.push_back(ret[j]);
                ret.back().push_back(nums[i]);
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> dp;
        dp.push_back({});
        int n = nums.size();

        for (auto i = 0; i < n; i++) {
            auto m = dp.size();
            for (auto j = 0; j < m; j++) {
                auto v = dp[j];
                v.push_back(nums[i]);
                dp.push_back(v);
            }
        }
        return dp;
    }
};

// 以下代码来自 pezy，为了学习二进制解法特在此参照。
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<int> set(nums.cbegin(), nums.cend());
        sort(set.begin(), set.end());
        int size = pow(2, set.size());
        vector<vector<int>> retv(size);
        for (int i=0; i<size; ++i)
            for (decltype(set.size()) j=0; j<set.size(); ++j)
                if ((i >> j) & 0x1) retv[i].push_back(set[j]);
        return retv;
    }
};
