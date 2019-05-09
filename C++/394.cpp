// 394 Decode String
//
// 给定一个加密的字符串，请解密其。解密规则为k[encoded_string]，即对加密字符串重复k次。
//
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
//


class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }  

    string decodeString(const string& s, int& i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            } else {
                int n = 0;
                while (i < s.size() && isdigit(s[i])) {
                    n = n * 10 + s[i++] - '0';
                }

                i++;
                string str = decodeString(s, i);
                i++;

                while (n-- > 0) {
                    res += str;
                }
            }
        }
        return res;
    }
};
