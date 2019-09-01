// 383 Ransom Note
//
// 看第一个字符串是否可以由给定的第二个字符串构成，检查各种边界条件。
//
// 利用哈希表来存储对应的值，先ran再mag，相减小于0则说明不存在相同的字符，则不可构成。
//

class Solution {
    bool canConstruct(string ran, string mag) {
        int hash[26] = {0};
        for (int i = 0; mag[i]; ++i) 
            hash[mag[i]-'a'] += 1;
        for (int i = 0; ran[i]; ++i) {
            hash[ran[i]-'a'] -= 1;
            if (hash[ran[i]-'a'] < 0) 
                return false;
        }
        return true;
    }
};
