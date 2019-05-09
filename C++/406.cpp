// 406 
//
// 每个人由一个pair表示，其中h表示该人的高度，k表示其前面有k个人的高度大于等于h。
//

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](cosnt pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };           
        sort(people.begin(), people.end());
        vector<pair<int, int>> res;
        for (auto& p : people)
            res.insert(res.begin() + p.second, p);
        return res;
    }  
};
