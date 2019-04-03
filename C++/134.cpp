// 134 Gas Station
//
// 有 N 个气站沿着环路，气站 i 的气体总量是 gas[i]。你的汽车可以加无限量的气，从气站 i 到气站 i+1 需要花费 cost[i]。假设你开始的时候在某一个气站，车上无气，问是否可以绕着环路顺时针走一圈，可以则返回气站的下标，否则返回 -1。
//
// 这个题目读起来比较费劲，翻译了一下，感觉还是不明晰。没办法，只能通过代码来进行翻译了，下面的代码来则 pezy。
//
//


class Solution {
public:
    int canCompeteCircuit(vector<int> &gas, vector<int> &cost) {
        int tank{0};
        int start{0};
        int stored{0};
        for (decltype(gas.size() i = 0; i < gas.size(); ++i) {
            if ((tank += gas[i] - cost[i]) < 0) {
                start = i + 1;
                stored += tank;
                tank = 0;
            }
        }
        return (tank + stored) < 0 ? -1 : start;
    }
};
