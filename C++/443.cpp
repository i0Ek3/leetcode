// 443 压缩字符串
//
// 我记得这是哪个公司的一道笔试题目来着，当时也没做出来。然后发现，很多公司的题目都是 LeetCode 上的，要么原题，要么稍微变下，感觉 lc 要是刷好了，笔试题目不成问题，可惜只怪我没有这个觉悟，现在开始苦逼的刷题。
//
// 倒也不晚，刷就是了！
//
// aabbbcccc -> a2b3c4
//
//

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();     
        int cnt = 1;
        int j = 0;
        for (int i = 1; i <= n; ++i, ++cnt) {
            if (i == n || chars[i] != chars[i-1]) {
                chars[j++] = chars[i-1];
                if (cnt >= 2) {
                    for (auto c : to_string(cnt)) {
                        chars[j++] = c;
                    }
                }
                cnt = 0;
            }
        }
        return j;
    }
};
