// 128 Longest Consecutive Sequence
//
// 给定一个未排序的整数数组，找出最大长度的可连续序列，O(n) 的复杂度。
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
// 那么先排序似乎就不太可能是最好的解法了，要不哈希表？但有复杂度的限制。
//

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ret = 1;
        for (auto &n : nums) {
            if (!set.count(n)) continue;
            set.erase(n);
            int pre = n - 1;
            int next = n + 1;
            while (set.count(pre)) set.erase(pre--);
            while (set.count(next)) set.erase(next++);
            ret = max(ret, next - pre - 1);
        }
        return ret;
    }
};
