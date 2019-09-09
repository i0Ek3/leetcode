// 460 LFU Cache
//
// 最不经常使用缓存算法实现。
//

class LFUCache {
    int cap, size, frequent;
    unordered_map<int, pair<int, int>> mp;
    unordered_map<int, list<int>::iterator> it; // 
    unordered_map<int, list<int>> freq;

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (!mp.count(key)) return -1; // 不存在该key
        freq[mp[key].second].erase(it[key]);
        mp[key].second++;
        freq[mp[key].second].push_back(key);
        it[key] = --freq[mp[key].second].end();
        if (!freq[frequent].size()) frequent++;
        return mp[key].first;
    }

    void put(int key, int val) {
        if (cap <= 0) return;
        int stored = get(key);
        if (stored != -1) {
            mp[key].first = val;
            return;
        }
        if (size >= cap) {
            mp.erase(freq[frequent].front());
            it.erase(freq[frequent].front());
            freq[frequent].pop_front();
            size--;
        }
        mp[key] = {val, 1};
        freq[1].push_back(key);
        it[key] = --freq[1].end();
        frequent = 1;
        size++;
    }
};
