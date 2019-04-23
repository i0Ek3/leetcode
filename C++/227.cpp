// 227 Basic Calculator II
//
// 实现一个简单的计算器来识别简单的表达式。表达式中只包含正整数的加减乘除运算和一个空格，求表达示的结果。
// 
// Input: "3+2*2"
// Output: 7
//
// Input: " 3+5 / 2 "
// Output: 5
//

class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') {
                total += term;
                in >> term;
                term *= 44 - op; // equal op == '+' ? 1 : -1
            } else {
                in >> n;
                if (op == "*") term *= n;
                else term /= n;
            }
        }
        return total;
    }
};
