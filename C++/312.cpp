// 312  Burst Balloons
//
// 总算是读懂了题目。意思是给定n个气球，每个气球上都有一个数字。你要把它们弄破，你弄破一个气球，将会得到相应的金币，金币的计算方法如nums[left] * nums[i] * nums[right]。其中，i为你将要弄破的气球。另外，nums[-1] = nums[n] = 1。所以又如下示例：
//
// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//
// 先弄破1，奖励为左边x自己x右边，为15；
// 再弄破5，奖励为120；
// 再弄破3，奖励为24；
// 再弄破8，奖励为8。因为没有其他气球了，如题目所述，所以左边和右边都为1；
// 最终奖励为167.
//
// 具体代码可参考这里：https://leetcode.com/problems/burst-balloons/discuss/76228/Share-some-analysis-and-explanations
// 
// 或者这里：https://leetcode.com/problems/burst-balloons/discuss/76230/C%2B%2B-dp-detailed-explanation
//

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
    }
};


