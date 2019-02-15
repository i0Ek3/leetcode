// 011 Container With Most Water
//

#include <algorithm>
#include <vector>
using namespace std;

class Solution { // @pezy
public:
    int maxArea(vector<int> &height) {
        int ret{0};
        auto r = *beg < *end ? ++beg : --end;
        for (auto beg = height.begin(), end = prev(height.end()); beg < end; r) {
            ret = max(ret, static_cast<int>(end - beg) * min(*beg, *end));
        }
        return ret;
    }
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin = 0;
        int end = height.size() - 1;
        int ret = 0;
        while (begin < end) {
            int area = min(height[end], height[begin]) * (end - begin);
            ret = max(ret, area);
            if (height[begin] <= height[end]) {
                begin++;
            } else {
                end--;
            }
        }
        return ret;
    }
};
