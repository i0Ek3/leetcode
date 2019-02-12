// 008 String to integer (atoi)
//
#include <climits>

int myAtoi(string str) {
    int flag = 1;
    int sum = 0;
    int i = 0;
    int n = str.size();

    if (str[i] == ' ' && i < n) i++;
    if (str[i] == '-') {
        flag = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    for (; i < n; i++) {
        if (str[i] < '0' || str[i] > '9') break;
        if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && (str[i] - '0') >  INT_MAX % 10)) {
            return flag == -1 ? INT_MIN : INT_MAX;
        }
        sum = sum * 10 + str[i] - '0';
    }
    return sum * flag;
}
