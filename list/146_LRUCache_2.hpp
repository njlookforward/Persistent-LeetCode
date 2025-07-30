#ifndef __LRUCACHE_HPP_2_
#define __LRUCACHE_HPP_2_

#include <unordered_map>
using std::unordered_map;

#include <iostream>
using std::cout, std::endl;

/**
 * @brief LRU的核心思想就是一个固定容量capacity的书架，get操作就是将找的书放在最上面
 * put操作，如有书架上有这本书(key)，那么放在最上面，更改版本；如果没有这本书，那么将新书放在最上面
 * 之后检查如果书架中的书已经超过了容量，那么从书架的最底层把最后一本书拿走
 */

class Node {
public:
    Node(int k, int v): _key(k), _value(v) {}
    Node() = default;

    int _key;    
    int _value;
    Node *_prev;
    Node *_next;
};

class LRUCache {
public:
    LRUCache(int capacity): _capacity(capacity), _dummy(new Node{}) {
        _dummy->_prev = _dummy;
        _dummy->_next = _dummy;
    }

    ~LRUCache() {
        int cnt = _key_to_Node.size() + 1;
        Node *pCur = _dummy;
        while (cnt > 0)
        {
            Node *pNext = pCur->_next;
            delete pCur;
            pCur = pNext;
            --cnt;
        }
        _dummy = nullptr;
    }

    // 这是接口函数
    int get(int key);
    void put(int key, int value);
    void print() const;

private:
    // 这是具体的实现函数，操作的对象就是双向链表
    void remove(Node *pNode);   // 从书堆中取出一本书
    void push_front(Node *pNode);   // 将一本书放到书堆的最上方
    Node *get_node(int key);    // 从书堆中查找书

private:
    int _capacity;  // LRU容量
    Node *_dummy = nullptr;  // 哨兵头结点，方便无论双向链表是否为空，都是一样的操作
    unordered_map<int, Node*> _key_to_Node; // 哈希表，为了O(1)时间内查找key对应的节点的位置
    // 双向链表实现了O(1)时间复杂度的插入和删除，结合哈希表可以实现O(1)时间复杂度的查找
};

inline void LRUCache::remove(Node *pNode) {
    pNode->_prev->_next = pNode->_next;
    pNode->_next->_prev = pNode->_prev;
}

inline void LRUCache::push_front(Node *pNode) {
    pNode->_prev = _dummy;
    pNode->_next = _dummy->_next;
    pNode->_prev->_next = pNode;
    pNode->_next->_prev = pNode;
}

inline Node *LRUCache::get_node(int key) {
    auto it = _key_to_Node.find(key);
    if(it == _key_to_Node.end())
        return nullptr;
    return it->second;
}

inline int LRUCache::get(int key) {
    auto it = get_node(key);
    if(it != nullptr) {
        remove(it);
        push_front(it);
    }
    return it ? it->_value : -1;
}

inline void LRUCache::put(int key, int value) {
    Node *pNode = get_node(key);
    if(pNode != nullptr) {
        pNode->_value = value;
        remove(pNode);
        push_front(pNode);
        return;
    }

    // 如果书堆上没有这本书，需要添加这本书
    _key_to_Node[key] = pNode = new Node{key, value};
    push_front(pNode);
    // 还需要查看此时是否超出LRUCache的容量
    if(_key_to_Node.size() > _capacity) {
        pNode = _dummy->_prev;
        _key_to_Node.erase(pNode->_key);
        remove(pNode);
        delete pNode;
    }
    
}

inline void LRUCache::print() const {
    int cnt = _key_to_Node.size();
    Node *pCur = _dummy->_next;
    while (cnt > 0)
    {
        cout << "(" << pCur->_key << ", " << pCur->_value << ") ";
        --cnt;
        pCur = pCur->_next;
    }
    cout << endl;
}
  
#endif