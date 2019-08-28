// 058 Length of Last Word
//
// Input: "Hello World"
// Output: 5
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        int last = s.size();
        int begin = 0;
        while (last > 0 && s[last-1] == ' ') last--;
        for (int i = 0; i < last; ++i) {
            if (s[i] == ' ') begin = i+1;
        }
        return last-begin;
    }
};
