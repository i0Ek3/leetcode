// 151 Reverse Words in a String
//
// 很简单的题目了吧，竟然下不了手，笔试的时候一看就是做过的题目，竟然写不出来。
//

class Solution {
public:
    string reverse(string s) {
        stringstream ss;
        string ans = "", tmp;
        ss << s;
        while (ss >> tmp) ans = " " + tmp + ans;
        if (ans != "") ans.erase(ans.begin());
        return ans;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        string tmp, ret;
        string::size_type idx = s.size();
        while (idx != 0) {
            tmp.clear();
            while (!isspace(s[--idx])) {
                tmp.push_back(s[idx]);
                if (idx == 0) break;
            }
            if (!tmp.empty()) {
                if (!ret.empty()) {
                    ret.push_back(' ');
                }
                std::reverse(tmp.begin(), tmp.end());
                ret.append(tmp);
            }
        }
        return ret;
    }
};
