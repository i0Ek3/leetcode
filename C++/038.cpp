// 038 Count and Say
//
// 给定该序列中的前五个元素，求序列中第 n 个元素是啥。但是具体过程我没弄懂，只能借助翻译了。
//
// 不过，我第一个想到的解法是递归，哈哈哈！然后在评论区找来找去，看着这个还能理解，也短小精悍，所以就它了！
//
//

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string item = "";
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            int count = 1;
            while (i < len - 1 && str[i] == str[i + 1]) {
                i++;
                count++;
            }
            item.append(to_string(count) + str[i]);
        }
        return item;
    }
};
