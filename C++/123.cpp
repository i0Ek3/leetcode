// 123 Best Time to Buy and Sell Stock III
//
// 和之前的题目类似，不过这个只允许你最多完成两笔交易。
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int firstBuy = INT_MIN;
        int firstSell = 0;
        int secondBuy = INT_MIN;
        int secondSell = 0;
        for (int i = 0; i < n; i++) {
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell - prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        return secondSell;
    }
};
