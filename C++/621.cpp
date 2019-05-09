// 621 class 
// 
// 给定一个字符数组代表计算机CPU需要处理的任务，不同字母代表着不同任务。给定n为冷却时间间隔，两个相同的任务之间在执行或者空闲的时候都必须至少有n个间隔，返回CPU完成指定任务数量的最少间隔数。
//
// 这个问题是真坑，翻译了老半天还模模糊糊！看大神们的答案还真是一种享受啊！
//
//
//

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        int cnt = 0;
        for (auto t : tasks) {
            map[t]++;
            int cnt = max(cnt, map[t]);
        }
        int ans = (cnt-1)*(n+1);
        for (auto m : map)
            if (m.second == cnt) ans++;
        return max((int)tasks.size(), ans);
    }  
};
