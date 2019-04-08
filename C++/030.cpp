// 030 Substring with Concatenation of All Words
//
// 给定一个字符串和一个单词长度相同的列表，后面不会翻译了，直接机翻吧。
//
// 查找s中子串的所有起始索引，该子串是单词中每个单词恰好连接一次，并且没有任何中间字符。
//
// 发现还是字符串的题目居多，真实让人头疼啊！
//

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        vector<int> idx;
        for (string word : words) {
            counts[word]++;
        }
        int n = s.size();
        int num = words.size();
        if (n == 0 || num == 0) return idx;
        int len = words[0].size();
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> un;
            int j = 0;
            for ( ; j < num; j++) {
                string word = s.substr(i+j*len, len);
                if (counts.find(word) != counts.end()) {
                    un[word]++;
                    if (un[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num)
                idx.push_back(i);
        }
        return idx;
    }
};
