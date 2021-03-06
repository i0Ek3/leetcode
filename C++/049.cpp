// 049 Group Anagrams
//
// 给定一个字符串数组，将字谜组合在一起。根据实例不难看出，题目要求你输出的每个数组中组成的单词的字母是相同的。
//
// 可以这样操作，用一个循环遍历所有字符串，如果组成字符串的字母相同的话，那么它们的 ascii 码之和是相等的。但要如何计算所有字符串的 ascii 之和呢？
//
// 看了一圈，就没人用我这个方法的，😂，几乎全是 unordered_map，好吧，让我来试着理解一下。
//
// 似乎，以后围绕这种类型的题目都可以考虑使用哈希表来解决。
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            string tmp = s; // 拷贝 strs 的值到 tmp 中
            sort(tmp.begin(), tmp.end()); // 将拷贝后的值进行排序
            m[tmp].push_back(s); // 把原本的值压入 m 中，即记录在 hashmap 中
        }
        for (auto i : m) { // 遍历 hashmap
            ret.push_back(i.second); // 将符合条件的结果放入 ret 中
        }
        return ret;
    }
};
