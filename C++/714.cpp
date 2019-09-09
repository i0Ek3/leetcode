// 714 买卖股票的最佳时机，含手续费
//
// 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
//
// 你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//
// 返回获得利润的最大值。
//
// 大家可以看着个帖子的介绍，是我见过讲的最好的关于动态规划的，我都看懂了！
//
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-2/
//

class Solution {
public:
    int maxProfix(vector<int>& prices, int fee) {
        int unhold = 0; // 不持有股票时最大利润
        int hold = -prices[0]; // 持有股票时最大利润
        for (int i = 1; i < prices.size(); ++i) {
            unhold = max(unhold, hold + prices[i] - fee);
            hold = max(hold, unhold - prices[i]);
        }
        return unhold;
    }
};
