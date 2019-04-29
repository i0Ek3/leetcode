// 412 Fizz Buzz
//
// 没懂啥意思～在看完别人的代码后，总算明白啥意思了，也就是说按照给定的数字范围输出对应的字符串，可以考虑不同乘除法，这样开销比较大，可以试着直接对内存进行操作。
//

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            res[i-1] = to_string(i);
        }
        for (int i = 2; i < n; i += 3) {
            res[i] = 'Fizz'; 
        }
        for (int i = 4; i < n; i += 5) {
            res[i] = 'Buzz';
        }
        for (int i = 14; i < n; i += 15) {
            res[i] = 'FizzBuzz';
        }
        return res;
    }  
};
