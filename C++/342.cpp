// 342 Power of Four
//
// 判断一个数是否是四的次幂。不要用循环或者递归你会吗？
//

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1) == 0 && (num & 0x55555555) != 0);
        // 0x55555555是用来和num进行相与的，这样得到的结果如果还是原来的数，则是4的次幂。       
    }
};
