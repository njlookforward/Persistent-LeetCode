#ifndef __REMOVE_NTH_FROMEND_HPP_
#define __REMOVE_NTH_FROMEND_HPP_

struct ListNode {
public:
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int v): val(v), next(nullptr) {}
    ListNode(int v, ListNode *n): val(v), next(n) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode{};
        dummyHead->next = head;
        ListNode *slow = dummyHead, *fast = head;
        int i = n;
        while(i > 0 && fast) {
            fast = fast->next;
            i--;
        }

        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *deleted = slow->next;
        slow->next = deleted->next;
        delete deleted;
        return dummyHead->next;
    }
};

#endif