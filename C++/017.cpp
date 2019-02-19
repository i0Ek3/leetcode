// 017 Letter Combinations of a Phone Number
//
//

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret{""}; // 存储最终结果
        // 构造字典
        array<string, 10> map{" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty()) return vector<string>();
        for (auto digit : digits) { // 迭代输入的字符串
            vector<string> temp; // 当前层
            for (const auto &pre : ret) { // 迭代 map 中字符下标
                for (auto c : map[digit-'0']) { // 迭代前层
                    temp.push_back(pre + c); // 临时存放当前层组合字符串
                }
            }
            ret = temp; // 组合后的最终字符串
        }
        return ret;
    }
};

