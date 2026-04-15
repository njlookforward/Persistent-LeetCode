#ifndef __SORTLIST_HPP_
#define __SORTLIST_HPP_

#include <queue>
using std::priority_queue;
#include <functional>
using std::greater;
#include <vector>
using std::vector;
#include <iostream>
using std::cout, std::endl;

class ListNode {
public:
    ListNode(): val(0), next(nullptr) {}
    ListNode(int d): val(d), next(nullptr) {}
    ListNode(int d, ListNode *n): val(d), next(n) {}

    int val;
    ListNode *next;
};

struct SingleList {
    SingleList() = default;
    void insert_tail(int v) {
        ListNode *pNew = new ListNode{v};
        if(_head == nullptr) {
            _head = pNew;
            _tail = pNew;
        } else {
            _tail->next = pNew;
            _tail = pNew;
        }
    }

    void print() const {
        ListNode *pCur = _head;
        while(pCur != nullptr) {
            cout << pCur->val << " ";
            pCur = pCur->next;
        }
        cout << endl;
    }

    ~SingleList() {
        ListNode *pCur = _head;
        while(pCur != nullptr) {
            ListNode *pNext = pCur->next;
            delete pCur;
            pCur = pNext;
        }
    }

    ListNode *_head = nullptr;
    ListNode *_tail = nullptr;
};

/**
 * @brief 
 * 时间复杂度 O(nlogn + n)
 * 空间复杂度 O(n)
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        priority_queue<int, vector<int>, greater<int>> bigHeap;
        ListNode *cur = head;
        while(cur != nullptr) {
            bigHeap.push(cur->val);
            cur = cur->next;
        }

        ListNode *newHead = nullptr, *tail = nullptr;
        while (!bigHeap.empty())
        {
            int val = bigHeap.top();
            ListNode *pNew = new ListNode{val};
            if(newHead == nullptr) {
                newHead = pNew;
                tail = pNew;
            } else {
                tail->next = pNew;
                tail = pNew;
            }
            bigHeap.pop();
        }
        
        return newHead;
    }
};

#endif