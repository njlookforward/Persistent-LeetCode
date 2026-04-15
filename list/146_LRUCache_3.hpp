#ifndef __LRUCACHE_3_HPP_
#define __LRUCACHE_3_HPP_

#include <unordered_map>
using std::unordered_map;
#include <list>
using std::list;
#include <utility>
using std::pair;
#include <iostream>
using std::cout, std::endl;

/**
 * @brief 在这个版本中，我需要使用标准库提供的双向链表，而不是自己设计，其实应该能用标准库就用标准库
 */

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity) {}
    ~LRUCache() {}
    
    // 接口函数
    int get(int key);
    void put(int key, int value);
    void print() const;

private:
    int _capacity;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _key_to_iter;
};

int LRUCache::get(int key) {
    auto it = _key_to_iter.find(key);
    if(it != _key_to_iter.end()) {
        // 说明找到了，应该改变位置
        // 问题：如果it->second指向的位置就是_list.begin()怎么办
        _list.splice(_list.begin(), _list, it->second);
        // _key_to_iter[key] = _list.begin();
        return it->second->second;
    }

    return -1;
}

void LRUCache::put(int key, int value) {
    auto it = _key_to_iter.find(key);
    if(it != _key_to_iter.end()) {
        it->second->second = value;
        _list.splice(_list.begin(), _list, it->second);
        // _key_to_iter[key] = _list.begin();
        return;
    }

    _list.emplace_front(key, value);
    _key_to_iter[key] = _list.begin();
    if(_key_to_iter.size() > _capacity) {
        _key_to_iter.erase(_list.back().first);
        _list.pop_back();
    }
}

void LRUCache::print() const {
    for (auto &entry : _list)
    {
        cout << "(" << entry.first << ", " << entry.second << ") ";
    }
    cout << endl;
}

#endif