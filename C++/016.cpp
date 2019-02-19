// 016 3Sum Closest
//

class Solution {
public:
    int threeClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int min = INT_MAX;
        int sum = 0;
        int temp = 0;

        for (auto it = nums.cbegin(); it != nums.cend(); ++it) { // 从前往后遍历
            for (auto begin = next(it), end = prev(nums.cend()); begin < end; temp > target ? --end; ++begin) { // begin 指向it的下一个元素，end 指向数组的最后一个元素
                if ((temp = *it + *begin + *end) == target) return target;
                else if (abs(temp - target) < min) {
                    sum = temp;
                    min = abs(temp - target);
                }
            }
        }
        return sum;
    }
};
