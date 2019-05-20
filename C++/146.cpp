// 146 LRU Cache
//
// 不用看题目了，通过 hashtable + 双向链表实现。实现基本的 put，get 操作。
//
// 最近访问的放在最前面，很久没访问的就删掉。
//
// 这道题目必须能手撕！
//

class LRUCache {
    int cap;
    list<pair<int, int>> lp;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1; // key not in m
        lp.splice(lp.begin(), lp, it->second); // move the key to the top
        return it->second->second; // return the value
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.find(key)) { // exist then delete
            lp.erase(it->second);
        }
        lp.push_front(make_pair<key, value>); // add new one
        m[key] = lp.begin();
        if (m.size() > cap) { // determine overflow
            int tmp = lp.rbegin()->first;
            lp.pop_back();
            m.erase(tmp); // delete always unused one
        }
    }
};
