// 326 Power of Three
//
// 3的幂。
//

class Solution {
public:
    bool isPowerOfThree(int n) {
        // return (n > 0 && pow(3, 20) % n == 0);
        if (n > 2) {
            while (n % 3 == 0) {
                n /= 3;
            }
        }
        return n == 1;
    }  
};
