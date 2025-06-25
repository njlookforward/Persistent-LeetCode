#ifndef DETECTCYCLE_HPP
#define DETECTCYCLE_HPP

#include <functional>
using std::equal_to;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int d): data(d), next(nullptr) {}
    ListNode(): data(0), next(nullptr) {}
};

/**
 * @brief 我需要找到循环的入口地址，需要定义快慢指针，如果快指针能够追上慢指针
 * 说明链表有环，否则没环，一个从相遇点开始走，一个从链表头开始走，相遇点就是链表的入口节点位置
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,
                 *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(equal_to<ListNode *>()(fast, slow))
                break;
        }
        
        if(!fast || !fast->next) return nullptr;

        ListNode *left = head,
                 *right = fast;
        while (!equal_to<ListNode *>()(left, right))
        {
            left = left->next;
            right = right->next;
        }
        
        return left;
    }
};

class Solution_carl {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head,
                 *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode *left = head;
                ListNode *right = slow;
                while (left != right)
                {
                    left = left->next;
                    right = right->next;
                }
                return left;
            }
        }
        return nullptr;
    }
};


#endif