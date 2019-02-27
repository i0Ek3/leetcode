// 167 Two Sum II
//
// 给定一个已经升序整数数组，找到两个数，使得它们的和等于指定值，并返回这两个数的索引，索引 1 不得大于索引 2.
//
// 采用双指针思路啊，i 指向开头，j 指向末尾。让它两所指向的值的和等于 sum，判断 sum 和 target 的大小，相等则输出索引，大于则 j 往回走，小于则 i 往前走。
//

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> res;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum < target) i++;
            else if (sum > target) j--;
            else {
                res = {i+1, j+1};
                return res;
            }
        }
        return res;
    }
};
