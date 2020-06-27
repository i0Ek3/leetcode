# Super Pow
# a ^ b % base

class Solution {
public:
    int base = 1337;
    
    // method 1
    int helper(int a, int b) {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= a;
            res %= base;
        }
        return res;
    }

    int superPow(int a, vector<int>&b) {
        if (b.empty()) return 1;
        int end = b.back();
        b.pop_back();
        int p1 = helper(a, end);
        int p2 = helper(superPow(a, b), 10)
        return (p1 * p2) % base;
    }

    // method 2
    int pow_(int a, int b) {
        if (!b) return 1;
        a %= base;
        if (b & 1) 
            return (a * pow_(a, b-1)) % base;
        else {
            int tmp = pow_(a, b/2);
            return (tmp * tmp) % base;
        }
    }
};
