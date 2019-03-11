// 084 Largest Rectangle in Histogram
//
// 给定 n 个非负整数代表这柱形图的高度，宽度都为 1，找到一个矩形区域，使得它的面积最大。感觉这道题类似于之前的 42 题。
//
// 所以我们需要考虑这么几种情况：
//  1. 不考虑所有宽度之和是否大于最大高度
//      1. 如果相邻的两个柱形图分别是最高和次高的，那么该矩形的最大面积就可能是 次高柱形图高度*2。
//      2. 如果不相邻，则要考虑二者之间其他柱形图的最小高度，此时的面积则可能为 柱形图最小高度*二者之间的柱形图个数。
//  2. 考虑宽度之和大于最大高度
//      1. 如果柱形图个数大于柱形图最大高度，则面积可能为 宽度之和*柱形图最小高度，其实类似于上面第二条了。
//
// 将以上几种情况的矩形面积列出，找出最大的即可，目前就是这个想法，至于如何编码实现，这才是难点。
//
// 看了一下大神们的答案，不是 stack 就是 DP，哈哈哈，我选择 stack。即将这些柱形图看作是一个栈结构，高度为 3 的那个栈顶。则依次往回计算面积，并记录这些面积。
//
//
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ret = 0;
        for (int i = 0; i < n || !st.empty(); ) {
            if (st.empty() || (i != n && heights[i] >= heights[st.top()])) st.push(i++);
            else {
                int tmp = st.top();
                st.pop();
                ret = max(ret, heights[tmp] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        return ret;
    }
};
