// 287 Find the Duplicate Number
//
// 找出给定数组中的重复数字。曾几何时的那么一瞬间，我也想用二分法来做。
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (auto i : nums)
                if (i <= mid) cnt++;

            if (cnt > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
