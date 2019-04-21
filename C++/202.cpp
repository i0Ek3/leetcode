// 202 Happy Number
//
// 写个算法来判断某个数字是否“快乐”。快乐的含义是输入任意一个非负整数，其可以分解为各位平方之和，知道该和为1.
//
// Input: 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
//
// 既然是简单难度，那就肯定有最漂亮的解法。感觉递归也是可以的呢！
//

class Solution {
publci:
    bool isHappy(int n) {
        unordered_map<int, int> un;
        while (n != 1) {
            if (um[n] == 0) um[n]++;
            else return false;
            int sum = 0;
            while (n != 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
        }
        return true;
    }
};

class Solution { // floyd's cycle detection algorithm
public:
    int next(int n) {
        int sum = 0;
        while (n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};
