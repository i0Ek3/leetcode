// 739 Daily Temperatures
//
// 每日温度。给定温度列表，输出需要等待几天可以渐暖。
//
//


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size()
        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < n &&  T[j] <= T[i]) {
                if (res[j] > 0) j = res[j] + j;
                else j = n;
            }
            if (j < n) res[i] = j - i;
        }
        return res;
    }
};
