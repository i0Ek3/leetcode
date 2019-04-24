// 238. Product of Array Except Self
//
// 给定一个包含n个整数的数组，返回一个数组，数组的第一个数为给定数组中前n个数的积，第二个数为i+1到n的积，以此类推。
//
// 就是说，返回的结果是除去数组中第一个数剩下的数的积。比较拗口，明白了就行！不能使用除法，O(n)限定。
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
//
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int first = 1;
        int last = 1;
        vector<int> ret(n, 1);
        for (int i = 0; i < n; i++) {
            ret[i] *= first;
            first *= nums[i];
            ret[n-1-i] *= last;
            last *= nums[n-1-i]
        }
        return ret;
    }
};
