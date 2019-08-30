// 058 Length of n Word
//
// Input: "Hello World"
// Output: 5
//

class Solution {
public:
    int lengthOfnWord(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        int cnt = 0;
        while (n > 0 && s[n-1] == ' ') n--;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') cnt = i+1;
        }
        return n-cnt;
    }
};
