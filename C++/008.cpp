// 008 String to integer (atoi)
//

class Solution {
public:
    int myAtoi(string str) {
        if (isalpha(str[0])) return 0;
        long long res = 0;
        int flag = 0; // -
        int len = 0; 
        int tmp = 0; // +-
        for (char c : str) {
            if ((c == '+' || c == '-') && len == 0) { // 判断正负号，并记录符号出现次数
                tmp++;
                flag = (c == '-') ? 1 : 0;
            } else if (0 <= (c-'0') && (c-'0') <= '9' && tmp < 2) { // 正负号只出现一次
                res = res * 10 + (c-'0');
                len++;
                if (res - 1 > INT_MAX) break; // 溢出 INT_MAX = 2147483647
            } else if (c == ' ' && len == 0 && tmp == 0) { // 如果是空格则继续，前提是前面没有出现正负号和数字
                continue;
            } else { // 英文和其他字符
                break;
            }
        }
        if (flag == 1) return -res < INT_MIN ? INT_MIN : -res;
        return res > INT_MAX ? INT_MAX : res;
    }
};


class Solution {
public:
    int myAtoi(string str) {
        int flag = 1;
        int sum = 0;
        int i = 0;
        int n = str.length();

        if (str.empty()) return 0;
        while (str[i] == ' ' || str[i] == '\t') i++;
        if (n == i) return 0;
        if (str[i] == '-') {
            flag = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        for (; i < n && isdigit(str[i]); i++) {
            if (sum > (numeric_limits<int>::max() - (str[i] - '0')) / 10) {
                return flag > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            sum *= 10;
            sum += str[i] - '0';
        }
        return sum * flag;
    }
};
