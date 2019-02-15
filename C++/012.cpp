// 012 Integer to Roman
//
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static string intToRoman(int num) {
        map<int, string> m = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string ret;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            while (num >= it->first) {
                ret += m[it->first];
                num -= it->first;
            }
        }
        return ret;
    }
};

int main()
{
    cout << Solution::intToRoman(2000) << endl;
    cout << Solution::intToRoman(1994) << endl;
    cout << Solution::intToRoman(3999) << endl;
    cout << Solution::intToRoman(-1) << endl;
}
