// 309 Best Time to Buy and Sell Stock with Cooldown
//
// 给定一个数组，为股票在某天的价格，设计一个算法算出最大的收益点。之前似乎有类似的题目，看起来非常眼熟。既然要找最大的利益点，那么可以考虑使用栈来存储当前最大的利益。
//
// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
//
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN);
        int sell(0);
        int pre_sell(0);
        int pre_buy;

        for (auto p : prices) {
            pre_buy = buy;
            buy = max(pre_sell-p, buy);
            pre_sell = sell;
            sell = max(pre_buy+p, sell);
        }
        return sell;
    }
};
