#ifndef LRF_CACHE_H
#define LRF_CACHE_H

#include <unordered_map>
#include <list>
#include <utility> // for std::pair

template<typename K, typename V>
class LRFCache {
private:
    using ListIter = typename std::list<std::pair<K, V>>::iterator;
    
    size_t capacity;
    std::list<std::pair<K, V>> cacheList; // Stores (key, value) pairs
    std::unordered_map<K, ListIter> cacheMap; // Maps key to list iterator

public:
    LRFCache(size_t capacity) : capacity(capacity) {}

    V get(K key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            throw std::out_of_range("Key not found");
        }
        
        // Move accessed item to front
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        return it->second->second;
    }

    void put(K key, V value) {
        auto it = cacheMap.find(key);
        
        if (it != cacheMap.end()) {
            // Update existing item
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            return;
        }
        
        if (cacheMap.size() >= capacity) {
            // Remove least recently used item
            auto last = cacheList.back();
            cacheMap.erase(last.first);
            cacheList.pop_back();
        }
        
        // Add new item to front
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }

    size_t size() const {
        return cacheMap.size();
    }
};

#endif // LRF_CACHE_H
