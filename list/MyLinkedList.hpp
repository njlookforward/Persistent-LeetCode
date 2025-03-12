#include <iostream>

struct MyLinkedNode {
    int _val = 0;
    MyLinkedNode *_next = nullptr;
    MyLinkedNode(int val): _val(val), _next(nullptr) {}
};

// implement with dummyhead;
struct MyLinkedList {
public:
    MyLinkedList(): _dummyhead(new MyLinkedNode(0)), _size(0) {}
    int get(int index) const;
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void print() const;

private:
    MyLinkedNode *_dummyhead = nullptr;
    int _size = 0;
};

inline int MyLinkedList::get(int index) const
{
    if(index >= _size || index < 0)
        return -1;
    
    MyLinkedNode *cur = _dummyhead->_next;
    while (index--)
    {
        cur = cur->_next;
    }
    return cur->_val;
}

inline void MyLinkedList::addAtHead(int val)
{
    // 需要注意MyLinkedList有两个数据成员，单链表的虚拟头结点和整个链表的长度，同步进行更新
    MyLinkedNode *newnode = new MyLinkedNode(val);
    newnode->_next = _dummyhead->_next;
    _dummyhead->_next = newnode;
    ++_size;
}

inline void MyLinkedList::addAtTail(int val)
{
    MyLinkedNode *newnode = new MyLinkedNode(val);
    MyLinkedNode *cur = _dummyhead;
    while(cur->_next)
        cur = cur->_next;
    cur->_next = newnode;
    ++_size;
}

inline void MyLinkedList::addAtIndex(int index, int val)
{
    if(index > _size || index < 0)
        return;
    
    MyLinkedNode *newnode = new MyLinkedNode(val);
    MyLinkedNode *cur = _dummyhead;
    while (index--)
    {
        cur = cur->_next;
    }
    newnode->_next = cur->_next;
    cur->_next = newnode;
    ++_size;
}

inline void MyLinkedList::deleteAtIndex(int index)
{
    if(index >= _size || index < 0)
        return;
    
    MyLinkedNode *cur = _dummyhead;
    while(index--)
    {
        cur = cur->_next;
    }
    MyLinkedNode *temp = cur->_next;
    cur->_next = cur->_next->_next;
    delete temp;
    --_size;
}

inline void MyLinkedList::print() const
{
    MyLinkedNode *cur = _dummyhead->_next;
    while (cur)
    {
        std::cout << cur->_val << " ";
        cur = cur->_next;
    }
}