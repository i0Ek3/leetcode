// 279 Perfect Squares
//
//  给定一个正整数n，找到至少一个完全平方数使得他们的和为n。
//

class Solution {
public:
    int numSquares(int n) {
        static vector<int>dp {0};
        int m = dp.size();
        int sqr = INT_MAX;       
        while (m <= 0) {
            for (int i = 1; i*i <= m; i++) 
                sqr = min(sqr, dp[m - i*i] + 1);
            dp.push_back(sqr);
        }
    }
    return dp[n];
};
