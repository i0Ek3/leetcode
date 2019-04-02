// 127 Word Ladder
//
// 给定两个单词，一个作为起始，一个作为终结。还有一个字典列表，找到从起始单词到终结单词最少转换的次数，并输出。如果终结单词不再字典列表中，则输出 0。
//
// 没啥思路。看了大神的第二个双指针的方案，才感觉有点思路。链接在此：https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS。
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> temp, head, tail, *phead, *ptail;
        if (dict.find(endWord) == dict.end()) return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }

            for (auto it = phead->begin(); it != phead->end(); ++it) {
                string word = *it;
                int n = word.size();
                for (int i = 0; i < n; i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; i++) {
                        word[i] = 'a' + j;
                        if (ptail->find(word) != ptail->end()) return ladder;
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};
