// 152 乘积最大子序列
//
//

public class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.length(); ++i) {
            if (sum > 0) sum *= i;
            else sum = i;
            ans = Math.max(ans, sum);
        }
        return ans;
    }
} 
