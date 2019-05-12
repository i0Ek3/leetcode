// 121 Best Time to Buy and Sell Stock
//
// 给定以个数组，下标为 i 的数字正好是第 i 天的股票价格。现在要求你完成一笔交易，是的利润最大。
//
// 初始想法是利用双指针前后开始遍历，显然这是不对的，毕竟这是 easy 的题目。
//

class Solution {
public:
    int maxProfit(vectot<int>& prices) {
        int sell = 0;
        int buy = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i] - buy);
        }
        return sell;
    }
};
