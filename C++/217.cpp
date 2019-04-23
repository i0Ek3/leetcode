// 217 Contains Duplicate
//
// 判断数组中是否有重复数字。
//
// Input: [1,2,3,1]
// Output: true
//
// Input: [1,2,3,4]
// Output: false
//
// 一下子想到的方法是数组中的数字相与，但似乎也没什么说服力。当然一些语言中也自带去重函数，那最为暴力的就是一个一个比较了，或者排序后再作比较。

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
        for (auto& num : nums) {
            if (m.find(num) != m.end()) return true;
            else m[num] = true;
        }
        return false;
    }
};
