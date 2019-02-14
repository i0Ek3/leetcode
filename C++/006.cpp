// 06 ZigZag Conversion
//
// 刚开始连题都没看懂，后来找了翻译才明白，原来是要输出这么个东西。
//
//   | | | |      |
//   |\|\|\|      |
//   | | | |      v
//
// 也就是所谓的Z 型齿，竖着看也许好一点。

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> v(numRows);
        int n = s.size();
        for (int i = 0; i < n;) {
            int p = 2 * numRows - 2;
            for (int j = 0; j < p && i < n; ++j, ++i)
                if (j < numRows) v[j].push_back(s[i]);
                else v[p - j].push_back(s[i]);
        }
        string ans = "";
        for (auto i : v) ans += i;
        return ans;
    }
};

