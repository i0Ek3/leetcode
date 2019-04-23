// 215 Kth Largest Element in an Array
//
// 找出数组中第k大的数字。
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
// https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/167837/Python-or-tm
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};
