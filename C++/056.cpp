// 056 Merge Intervals
//
// 给定一个区间的整数集合，合并那些有重叠的区间。比如 [1, 3] 和 [1, 5]，后者已经包括前者了。当然，这里的意思是说只要两个区间有交集就算是重叠。如 [1，3]，[2，6] 可以合并为 [1, 6]。
//
// 那应该怎么做呢？比较前一个区间中的后一个数和下一个区间的前一个数，如果大于等于，则合并。
//
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){ return a.start < b.start; }); // 这里使用 lambda 表达式

        for (int i = 0; i < n; i++) {
            if (!ret.empty() && intervals[i].start <= ret.back().end) {
                ret.back().end = max(intervals[i].end, ret.back().end);
            } else ret.push_back(intervals[i]);
        }
        return ret;
    }
};

