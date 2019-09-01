// 415 Add String 
//
// Add to string num1 and num2.
//

class Solution {
public: 
    string addString(string num1, string num2) {
        string res; 
        int tmp = 0, i = num1.size(), j = num2.size();
        while (i >= 0 || j >= 0 || tmp != 0) {
            if (i >= 0) tmp += num1[i--] - '0';
            if (j >= 0) tmp += num2[j--] - '0';
            res += to_string(tmp % 10);
            tmp /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
