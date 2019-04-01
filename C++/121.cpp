// 121 Best Time to Buy and Sell Stock
//
// 给定以个数组，下标为 i 的数字正好是第 i 天的股票价格。现在要求你完成一笔交易，是的利润最大。
//
// 初始想法是利用双指针前后开始遍历，显然这是不对的，毕竟这是 easy 的题目。
//

class Solution {
public:
    int maxProfit(vectot<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};
