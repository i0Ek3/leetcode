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
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        int begin = 0, now = 1;
        for (size_t i = 1; i <= n; i++) {
            if (s[i-1] == '0') now = 0;
            if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) begin = 0;
            int tmp = now;
            now = begin + now;
            begin = tmp;
        }
        return now;
    }
};

