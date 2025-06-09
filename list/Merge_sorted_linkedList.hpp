#ifndef MERGE_SORTED_LINKEDLIST_HPP
#define MERGE_SORTED_LINKEDLIST_HPP

struct Node {
    int data;
    Node *next;

    Node(): data(0), next(nullptr) {}
    Node(int x): data(x), next(nullptr) {}
    Node(int x, Node *pnext): data(x), next(pnext) {}
};

class Solution {
public:
    Node *merge_sorted_linkedlist(Node *list1, Node *list2) {
        Node *newListHead = nullptr;
        Node *newListTail = nullptr;
        while (list1 != nullptr && list2 != nullptr)
        {
            Node *target = nullptr;
            if(list1->data < list2->data) {
                target = list1;
                list1 = list1->next;
            } else {
                target = list2;
                list2 = list2->next;
            }

            if(newListHead == nullptr) {
                newListHead = target;
                newListTail = target;
            } else {
                newListTail->next = target;
                newListTail = target;
            }
        }

        newListTail->next = nullptr;
        return newListHead;
    }
};


#endif