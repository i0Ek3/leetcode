// 008 String to integer (atoi)
//

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
