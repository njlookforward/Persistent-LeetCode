#ifndef __LRUCACHE_HPP_
#define __LEUCACHE_HPP_

#include <unordered_map>
using std::unordered_map;

#include <iostream>
using std::cout, std::endl;

/**
 * 方法一：自定义双向链表，需要自己维护双向链表的增删
 * 因为要求get是O(1)，因此需要使用哈希表；put也是O(1)，需要使用双向链表
 */
// 自定义双向链表
struct Node {
    int m_key;
    int m_value;
    Node *m_prev;
    Node *m_next;
};

class LRUList {
public:
    // 初始化
    LRUList();
    // 析构函数
    ~LRUList();
    // 增加
    void listInsert(Node *pNew);
    // 删除
    void listDelete(Node *pNode);
    // 改变
    void listUpdate(Node *pNode);
    // 查找
    int getSize() const {   return size;    }
    Node *getKicked() {   return dummyhead->m_prev;   }
    void listPrint() const;

private:
    Node *dummyhead = nullptr;
    int size = 0;
};


class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void print() const;
private:
    int m_capacity = 0;
    LRUList m_list;
    unordered_map<int, Node*> m_u_map;
};

inline LRUList::LRUList(): dummyhead(new Node{}), size(0) {
    dummyhead->m_prev = dummyhead;
    dummyhead->m_next = dummyhead;
}

inline LRUList::~LRUList() {
    Node *pCur = dummyhead;
    int cnt = size + 1;
    while(cnt != 0) {
        Node *pNext = pCur->m_next;
        delete pCur;
        --cnt;
        pCur = pNext;
    }
}

inline void LRUList::listInsert(Node *pNew) {
    pNew->m_prev = dummyhead;
    pNew->m_next = dummyhead->m_next;
    pNew->m_prev->m_next = pNew;
    pNew->m_next->m_prev = pNew;
    ++size;
}

inline void LRUList::listDelete(Node *pNode) {
    pNode->m_prev->m_next = pNode->m_next;
    pNode->m_next->m_prev = pNode->m_prev;

    delete pNode;
    pNode = nullptr;
    --size;
}

inline void LRUList::listUpdate(Node *pNode) {
    // 先删
    pNode->m_prev->m_next = pNode->m_next;
    pNode->m_next->m_prev = pNode->m_prev;
    // 后插
    pNode->m_prev = dummyhead;
    pNode->m_next = dummyhead->m_next;
    pNode->m_prev->m_next = pNode;
    pNode->m_next->m_prev = pNode;
}

inline void LRUList::listPrint() const {
    Node *pCur = dummyhead->m_next;
    int cnt = size;
    while(cnt) {
        cout << "(" << pCur->m_key << ", " << pCur->m_value << ") ";
        pCur = pCur->m_next;
        --cnt;
    }
    cout << endl;
}

// bug: 不要忘记写作用域限定符，这是我出现问题的主要原因
inline LRUCache::LRUCache(int capacity): m_capacity(capacity) {}
inline int LRUCache::get(int key) {
    auto resiter = m_u_map.find(key);
    if(resiter == m_u_map.end())
        return -1;
    Node *pNode = resiter->second;
    m_list.listUpdate(pNode);
    return pNode->m_value;
}

inline void LRUCache::put(int key, int value) {
    // 有就更新
    auto resIter = m_u_map.find(key);
    if(resIter != m_u_map.end()) {
        Node *pNode = resIter->second;
        pNode->m_value = value;
        // bug2: 没有更新LRUCache，因为又重新访问了，虽然只是修改value值
        m_list.listUpdate(pNode);
        return;
    }
    // 没有需要检查，如果链表满了，需要先删后插，修改哈希表；
    if(m_list.getSize() == m_capacity) {
        // 删除最后一个节点，然后更新哈希表
        Node *pNode = m_list.getKicked();
        // bug: 应该先删除哈希表中的值，因为如果交换顺序，pNode中的值全部消失了，所以就无法删除哈希表中对应的值
        m_u_map.erase(pNode->m_key);
        m_list.listDelete(pNode);
        
    }
    // 没有满的话，直接插入，修改哈希表
    Node *pNew = new Node{};
    pNew->m_key = key;
    pNew->m_value = value;
    m_list.listInsert(pNew);
    m_u_map.insert({key, pNew});
}

inline void LRUCache::print() const {
    cout << "LRUCache's capacity = " << m_capacity << " "
         << "LRUCache's size = " << m_list.getSize() << endl;
    if(m_list.getSize() != 0) {
        m_list.listPrint();
    }
    cout << endl;
}

#endif