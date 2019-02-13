// 009 Parlindrome Number


class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long reverse{0}, origin{x}; // 避免溢出
        do {
            reverse = reverse * 10 + x % 10; // 逆向存储
        } while (x /= 10);
        return reverse == origin;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while (x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};
