// 122 Best Time to Buy and Sell Stock II
//
// 基本规则同上一道，不过这次可以进行多次交易。
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int sell = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            sell += max(0, prices[i] - prices[i-1]);
        }
        return sell;
    }
};
