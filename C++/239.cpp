// 239 Sliding Window Maximum
//
// 就是一个滑动窗口，不断移动窗口，将窗口里的最大值组成一个新的数组输出。实际工程中可能会用到，我猜的。
//
// 单调队列问题，第一次听说这个名词，但应该不陌生才对，反正是和队列有关系。
//
// 其实单调栈和单调队列是有相似之处的。对于单调栈来说，单调就意味着递增或者递减了。对于单调队列来说，单调意味着递增。具体可以看这里：https://endlesslethe.com/monotone-queue-and-stack-tutorial.html
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buf;
        vector<int> ret;

        for (auto i = 0; i < nums.size(); i++) {
            while (!buf.empty() && nums[i] >= nums[buf.back()])
                buf.pop_back();
            buf.push_back(i);

            if (i >= k - 1) ret.push_back(nums[buf.front()]);
            if (buf.front() <= i - k + 1) buf.pop_front();
        }
        return ret;
    }
};
