// 014 Longest Common Prefix
//

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return ""; // 非要验证空字符串
        for (size_t ix = 0; ix < strs[0].size(); ix++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][ix] != strs[0][ix]) { // 判断第二个字符串和第一个字符串
                    return strs[0].substr(0, ix); // 返回第一个字符串的 0-ix 子串
                }
            }
        }
        return strs[0];
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string> &str) {
        if (strs.empty()) return ""; // 非要验证空字符串
        for (size_t i = 0; i < strs.front().size(); ++i) { // 纵向扫描
            for (const auto &str : strs) { // 范围迭代
                if (i == str.size() || str.at(i) != strs.front().at(i)) {
                    return strs.front().substr(0, i);
                }
            }
        }
        return strs.front();
    }
};
