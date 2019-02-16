// 013 Roman to Integer
//
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution1 {
public:
    static int romanToInteger(string s) {
        map<char, int> m = {
            { 'I' , 1 },
            { 'V' , 5 },
            { 'X' , 10 },
            { 'L' , 50 },
            { 'C' , 100 },
            { 'D' , 500 },
            { 'M' , 1000 }
        };
        int ret = m[s.back()];
        int n = s.length();
        for (int i = n - 2; i >= 0; --i) { // 从后开始往前遍历
            if (m[s[i]] < m[s[i + 1]]) { // 比较最后两个，依次往前
                ret -= m[s[i]]; // 小则说明运算减法，如 IV
            } else { // >= 则为加法，如 II
                ret += m[s[i]];
            }
        }
        return ret;
    }
};



int main() {
    cout << Solution1::romanToInteger("LVIII") << endl;
    cout << Solution1::romanToInteger("MCMXCIV") << endl;
}
