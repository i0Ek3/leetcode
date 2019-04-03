// 139 Word Break
//
// 给定一个非空字符串和一个包含非空单词的列表，判断它是否可以被分成一个或多个字典单词，以空格分隔的序列？
//
// 可能我翻译的有问题，但答题意思应该是明确的。
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for (auto w : wordDict)
            dict.insert(w);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                    string word = s.substr(j, i - j + 1);
                    if (dict.find(word) != dict.end())
                        dp[i + 1] = dp[i + 1] || dp[j];
                    if (dp[i+1]) break;
            }
        }
        return dp[s.size()];
    }
};
