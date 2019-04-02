// 131 Palindrome Partitioning
//
// 给定一个字符串 s，将 s 分为几个子串，且每个字串都是回文串，返回所有可能的子串。
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
// 首先单个的字符都可以构成回文子串，其次相同的字符也可以，最后再判断单独的回文串。
//
//

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (s.empty()) return ret;
        vector<string> path;
        dfs(0, s, path, ret);
        return ret;
    }

    void dfs(int index,
             string& s,
             vector<string>& path,
             vector<vector<string>>& ret)
    {
        if (index == s.size()) {
            ret.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isP(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }

    bool isP(const string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

