// 208 实现一个字典树
//
// 实现字典树的插入查找和startWith方法。
//
// 不知道字典树的就先去查一下把，我也只能说出个大概。https://github.com/i0Ek3/awesome-architect/blob/master/record/Trie树.md
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
//

class TrieNode {
public:
    TrieNode *next[26];
    bool isWord;

    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        isWord = b;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < s.size(); ++i) {
            if (p->next[s[i] - 'a'] == nullptr) {
                p->next[s[i] - 'a'] = new TrieNode();
            }
            p = p->next[s[i] - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word) {
        TrieNode *p = find(key);
        return p != nullptr && p->isWord;
    }

    bool startWith(string prefix) {
        return find(prefix) != nullptr;
    }
private:
    TrieNode* find(string key) {
        TrieNode *p = root;
        for (int i = 0; i < key.size() && p != nullptr; ++i) {
            p = p->next[key[i] - 'a'];
        }
        return p;
    }
};
