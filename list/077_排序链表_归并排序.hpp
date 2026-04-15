#ifndef __SORTLIST_HPP_
#define __SORTLIST_HPP_

#include <iostream>
using std::cout, std::endl;

/**
 * @brief 使用自顶向下归并排序链表，之前排序的数组，需要使用辅助数组所以空间复杂度为O(n)
 * 但是这时候使用的是单链表，因此不需要使用辅助数组，需要借助一个dummy头结点统一插入与删除操作而已
 * 需要使用递归：先分为两部分，长度差不超过1，然后分别排序，最后合并在一起
 * 时间复杂度为O(nlogn) 空间复杂度为O(logn)，这是函数调用栈的深度
 */
struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int v): val(v), next(nullptr) {}
    ListNode(int v, ListNode *n): val(v), next(n) {}
};

class Solution_merge {
public:
    ListNode *split(ListNode *head);
    ListNode *merge(ListNode *head1, ListNode *head2);
    ListNode *sortList(ListNode *head) {
        // 递归终止条件
        if(head == nullptr || head->next == nullptr) return head;
        // 1. 先分为两段
        ListNode *secondHead = split(head);
        // 2. 分别排序
        head = sortList(head);
        secondHead = sortList(secondHead);
        // 3. 合并排序
        return merge(head, secondHead);
    }

    void print(ListNode *head) {
        ListNode *pCur = head;
        while(pCur != nullptr) {
            cout << pCur->val << " ";
            pCur = pCur->next;
        }
        cout << endl;
    }
};

/**
 * @brief 需要使用快慢指针将单链表分为两段，slow = head; fast = head->next;
 * 必须这样写才能得到两段，不能从同一节点出发，考虑边界，只有2个节点的情况，只有不同出发点才能分割
 * @note next作用域好好处理，必须断开单链表
 * 能够进入split说明至少有两个节点
 */
ListNode *Solution_merge::split(ListNode *head) {
    ListNode *slow = head, *fast = head->next;
    // 修改: 使用标准的快慢指针方法，确保不会访问空指针
    // bug: 边界条件错误了，fast != nullptr -> fast->next; fast->next != nullptr -> fast->next->next
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *secondHead = slow->next;
    slow->next = nullptr;
    return secondHead;
}

ListNode *Solution_merge::merge(ListNode *head1, ListNode *head2) {
    ListNode *dummy = new ListNode{};
    ListNode *pCur = dummy;
    while(head1 && head2) {
        if(head1->val < head2->val) {
            pCur->next = head1;
            head1 = head1->next;
        } else {
            pCur->next = head2;
            head2 = head2->next;
        }
        pCur = pCur->next;
    } 
    // bug1: 不是pCur->next，而是pCur
    if(head1 != nullptr)
        pCur->next = head1;
    else if(head2 != nullptr) 
        pCur->next = head2;

    ListNode *head = dummy->next;
    delete dummy;
    return head;
}

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
        _head = nullptr;
    }

    ListNode *_head = nullptr;
    ListNode *_tail = nullptr;
};

#endif