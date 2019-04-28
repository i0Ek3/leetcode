// 315 Count of Smaller Numbers After self 
//
// 找出数组中除自己之外的每个数字之后比自己小的数的个数，输出为一个数组。这句话被我翻译的如此拗口，很是优秀。
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element. 
//

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            result[i] = it - res.begin();
            res.insert(it, nums[i]);
        }
        return result;
    }  
};
