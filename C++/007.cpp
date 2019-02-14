// 007 Reverse Integer
//
#include <climits> // for macro INT_MAX

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        // 判断溢出情况
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main()
{
    reverse(123);
    reverse(-123);
    reverse(120);
    return 0;
}
