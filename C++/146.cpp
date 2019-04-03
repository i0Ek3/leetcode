// 146 LRU Cache
//
// 不用看题目了，通过 hashtable + 双向链表实现。实现基本的 put，get 操作。
//
// 最近访问的放在最前面，很久没访问的就删掉。
//
// 这道题目必须能手撕！
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct Cache {
    int _key;
    int _value;
    Cache(int key = 0, int value = 0) {
        _key = key;
        _value = value;
    }
};

class Solution {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        auto it = um[key]; // 寻找 key 的位置
        cache.push_front(*it); // 将找到的值移至最前面
        cache.erase(it); // 清除原始位置的副本
        um[key] = cache.begin(); // 更新 key 的位置为 begin()
        return um[key]->_value;
    }

    void put(int key, int value) {
        // 如果没有 key 在 cache 中，则插入之
        if (um.find(key) == um.end()) {
            cache.push_front(Cache(key, value)); // 在缓存中插入值
            um[key] = cache.begin();
            if (cache.size() > _capacity) { // 如果当前缓存大小大于缓存的容量，则删除最后这一个值
                Cache lastNode = cache.back();
                um.erase(lastNode._key);
                cache.pop_back();
            }
        } else { // 如果找到，则更新值的位置
            auto it = um[key];
            it->_value = value;
            cache.push_front(*it);
            cache.erase(it);
            um[key] = cache.begin();
        }
    }

private:
    list<Cache> cache;
    unordered_map<int, list<Cache>::iterator> um;
    int _capacity;
};
