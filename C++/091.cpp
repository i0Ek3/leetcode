// 091 Decode Ways
//
// 将 A - Z 编码为 1 - 26，给定一个数字组合如 224，请输出有几种解码方式。
//
// 224 可以看作 2 和 24 或者 2  2  4 或者 22 和 4，则有三种解码方式。想象大脑是如何想出该解法的，编码实现。
//
// 我们来分析一下，其实就是类似排列。我觉着递归或者 DFS 都可以做。可是如何分割数字呢？
//
// 发现后面的题感觉难度增加了呢？理解起来很是费劲。下面的答案是摘自评论区的，哪位大神来解释一下？
//
class Solution {
public:
    int numdecodings(string s) {
        int cnt = 0;
        if (s.size() == 0 || (s.size() == 1 && s[0] == '0')) return 0;
        if (s.size() == 1) return 1;

        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;

        for (int i = 0; i < s.size(); ++i) {
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if (i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')))
                dp[i+1] += dp[i-1];
        }
        return dp.back();
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        int begin = 0, res = 1;
        
        for (size_t i = 1; i <= n; i++) {
            if (s[i-1] == '0') res = 0;
            if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) begin = 0;
            int tmp = res;
            res = begin + res;
            begin = tmp;
        }
        return res;
    }
};

