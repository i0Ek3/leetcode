// 169 Majority Element
//
// 给定有 n 个元素的数组，找到出现 ⌊ n/2 ⌋ 多次的数。
//
// Input: [3,2,3]
// Output: 3
//
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
// 可参考这里：https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C%2B%2B-with-Explanations
//

class Solution {
public:
    // HashTable
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++cnt[nums[i]] > n/2) return nums[i];
    }

    // Moore Voting Algo
    int majorityElement2(vector<int>& nums) {
        int major = 0;
        int n = nums.size();
        for (int i = 0;, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCnt++;
                if (bitCnt > n/2) {
                    major |= mask;
                    break;
                }
            }
        }
        return major;
    }
};
