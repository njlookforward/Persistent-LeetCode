#ifndef SOLUTION_LRU_H
#define SOLUTION_LRU_H

#include <list>
#include <unordered_map>
#include <utility>
#include <optional>     // C++17之后可以使用的库

using namespace std;

/**
 * @brief LRU算法就可以看做一端受限的书架，每次get从书架中找到书并拿到最上面，并更新值，如果没有返回空
 * 每次put先查看书架中是否有书，如果有书，那么直接放到最上面，如果没有书，那么先查看书架是否已经满了，如果满了，就扔掉最后一本书，然后把新书放在最上面
 */
template <typename K, typename V>
class LRU {
public:
    LRU(size_t capacity): capacity_(capacity) {}
    // 根据键从缓存中找到对应的值
    std::optional<V> get(const K &key) {
        // 查找值
        auto iter = index_.find(key);
        // 判断是否找到
        if(iter == index_.end()) {
            // 没找到，返回空
            return std::nullopt;
        } else {
            // 找到，保存值，然后拿到最上面
            std::optional<V> val(iter->second->second);
            cache_.splice(cache_.begin(), cache_, iter->second);
            return val;
        }
    }

    // 添加新的键值对到缓存中
    void put(const K &key, const V &value) {
        // 查找是否能够找到
        auto iter = index_.find(key);
        if(iter != index_.end()) {
            // 找到，更新值，并放在最上面
            iter->second->second = value;
            cache_.splice(cache_.begin(), cache_, iter->second);
            return;
        } else {
            // 没找到，查看cache_大小，判断是否需要删除最后一个元素，还要更新index_
            if(cache_.size() == capacity_) {
                K deletedKey = cache_.back().first;
                cache_.pop_back();
                index_.erase(deletedKey);
            }
            // 将新的键值对添加到cache，更新index
            cache_.emplace_front(key, value);
            index_.insert({key, cache_.begin()});
        }
    }

private:
    size_t capacity_;       // LRU缓存容量
    list<pair<K, V>> cache_;        // LRU缓存
    unordered_map<K, std::list<std::pair<K, V>>::iterator> index_;  // LRU索引
};


#endif  // SOLUTION_LRU_H