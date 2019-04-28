// 347 Top K Frequent Elements
//
// 给定一个非空整数数组，返回经常访问的前k个数。
//
// 要不就先排序一下嘛，以前是第k大。
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) m[n]++;
        
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > m.size() - k) {
                res.push_back(res.top().second);
                pq.pop();
            }
        }
        return res;
    }  
};
