// 022 Generate Parentheses
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis (int n) {
        if (n == 0) return vector<string>(1, "");
        if (n == 1) return vector<string>(1, "()");
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            for (auto inner : generateParenthesis(i)) {
                for (auto outer : generateParenthesis(n-1-i)) {
                    ret.push_back("(" + inner + ")" + outer);
                }
            }
        }
        return ret;
};
