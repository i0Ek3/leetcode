// 334 Increasing Triplet Subsequence
//
// 给定一个未排序的数组，判断它是否是包含三个长度的递增子序列？
//
//

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (auto n : nums) {
            if (n <= a) {
                a = n;
            } else if (n <= b) {
                b = n;
            } else {
                return true;
            }
        }
        return false;
    }
};
