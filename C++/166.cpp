// 166 Fraction to Recurring Decimal
//
// 给定两个整数，代表分子和分母，返回该分式的字符串形式。除不尽的用括号表示，如示例3.
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
// 果然没我想的那么简单，忘了判断正负号，小数点之类的。参考：https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51189/0ms-clear-c%2B%2B-solution-with-explanations!
//


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        typedef ll long long // avoid to overflow

        stringstream ss1, ss2;
        ll n = numerator;
        ll d = denominator;
        ll q = n / d;
        ll r = n % d;

        if (q == 0 && (n > 0 && d < 0) || (n < 0 && d > 0)) ss << "-";
        ss1 << q;
        if (r) ss1 << ".";
        unordered_map<ll, int> m;
        int i = 0;
        if (r < 0) r = -r;
        if (d < 0) d = -d;
        while (r) {
            n = r * 10;
            if (m.find(n) == m.end()) {
                q = n / d;
                r = n % d;
                ss2 << q;
                m[n] = i++;
            } else {
                return ss1.str() + ss2.str().substr(0, m[n]) + '(' + ss2.str().substr(m[n]) + ')';
            }
        }
        return ss1.str() + ss2.str();
    }
};
